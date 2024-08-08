#include "GraphicsSdl2Impl.h"

#include "Sdl2Helpers.h"

#include "clsn/ui/UIManager.h"

#include "clsn/draw/font.h"
#include "clsn/draw/point.h"
#include "clsn/draw/region.h"

#include "clsn/core/system.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#include <SDL_ttf.h>

#include <iostream> //ETOTODO: TO REMOVE

namespace
{
    auto getFontFromCache(const clsn::draw::font& font,
                          const clsn::ui::impl::sdl2::Sdl2FontCache& fontCache)
        -> TTF_Font*
    {
        auto optionalRefFont = fontCache.get_font(font);
        if (!optionalRefFont.has_value())
        {
            clsn::core::system::panic("font not found");
            return nullptr;
        }

        return &optionalRefFont.value().get();
    }

    auto getTextSizeImpl(TTF_Font* ttfFont, std::string_view text)
        -> clsn::draw::dimension
    {
        int actualTextWidth, actualTextHeight;
        TTF_SizeText(ttfFont, text.data(), &actualTextWidth, &actualTextHeight);
        return {actualTextWidth, actualTextHeight};
    }

}

namespace clsn::ui::impl::sdl2
{
    using namespace clsn::draw;

    GraphicsSdl2Impl::GraphicsSdl2Impl(
            SDL_Renderer& renderer,
            const dimension& size)
    : m_renderer{renderer}
    , m_drawColor{255, 255, 255}
    , m_needToApply{false}
    {
        createTexture(size);
    }

    GraphicsSdl2Impl::~GraphicsSdl2Impl()
    {
        destroyTexture();
    }

    Sdl2FontCache& GraphicsSdl2Impl::getFontCache() noexcept
    {
        return m_fontCache;
    }

    const Sdl2FontCache& GraphicsSdl2Impl::getFontCache() const noexcept
    {
        return m_fontCache;
    }

    void GraphicsSdl2Impl::resize(const dimension& newSize)
    {
        destroyTexture();
        createTexture(newSize);
    }

    void GraphicsSdl2Impl::destroyTexture()
    {
        if (m_texture != nullptr)
        {
            SDL_DestroyTexture(m_texture);
        }
    }

    void GraphicsSdl2Impl::createTexture(const dimension& newSize)
    {
        using namespace std::string_literals;

        m_texture = SDL_CreateTexture(
            &m_renderer,
            SDL_PIXELFORMAT_RGBA8888,
            SDL_TEXTUREACCESS_TARGET,
            newSize.get_width(),
            newSize.get_height());

        if (m_texture == nullptr)
        {
            SDL_Log("Error while creating texture: %s", SDL_GetError());
            SDL_DestroyRenderer(&m_renderer);
            system::panic("Error while creating texture: "s + SDL_GetError());
            return;
        }

        SDL_SetRenderTarget(&m_renderer, m_texture);
    }

    void GraphicsSdl2Impl::setDrawColor(const color& c) const
    {
        m_drawColor = c;

        SDL_SetRenderDrawColor(
            &m_renderer, c.get_red(), c.get_green(), c.get_blue(), c.get_alpha());
    }

    void GraphicsSdl2Impl::clear() const
    {
        SDL_RenderClear(&m_renderer);
    }

    void GraphicsSdl2Impl::apply() const
    {
        if (m_needToApply)
        {
            SDL_SetRenderTarget(&m_renderer, nullptr);
            SDL_RenderClear(&m_renderer);
            SDL_RenderCopy(&m_renderer, m_texture, nullptr, nullptr);
            SDL_RenderPresent(&m_renderer);

            SDL_SetRenderTarget(&m_renderer, m_texture);

            m_needToApply = false;
        }
    }

    void GraphicsSdl2Impl::drawLine(const point& p1, const point& p2) const
    {
        SDL_RenderDrawLine(
            &m_renderer, p1.get_x(), p1.get_y(), p2.get_x(), p2.get_y());

        m_needToApply = true;
    }

    void GraphicsSdl2Impl::drawRectangle(const region& r) const
    {
        SDL_Rect rect = Sdl2Helpers::toSDL(r);
        SDL_RenderDrawRect(&m_renderer, &rect);

        m_needToApply = true;
    }

    void GraphicsSdl2Impl::drawFillCircle(const region& r) const
    {
        auto cx = static_cast<const short>(r.get_x() + r.get_width() / 2);
        auto cy = static_cast<const short>(r.get_y() + r.get_height() / 2);
        auto rx = static_cast<const short>(r.get_width() / 2);
        auto ry = static_cast<const short>(r.get_height() / 2);

        filledEllipseRGBA(&m_renderer, cx, cy, rx, ry,
            m_drawColor.get_red(),
            m_drawColor.get_green(),
            m_drawColor.get_blue(), 255);

        m_needToApply = true;
    }

    void GraphicsSdl2Impl::drawFillRectangle(const region& r) const
    {
        SDL_Rect rect = Sdl2Helpers::toSDL(r);
        SDL_RenderFillRect(&m_renderer, &rect);

        m_needToApply = true;
    }

    void GraphicsSdl2Impl::drawText(const region& r,
                                    const font& font,
                                    std::string_view text) const
    {
        auto ttfFont = getFontFromCache(font, m_fontCache);
        SDL_Color textColor = Sdl2Helpers::toSDL(m_drawColor);

        SDL_Surface* surface =
            TTF_RenderText_Blended(ttfFont, text.data(), textColor);

        SDL_Texture* texture =
            SDL_CreateTextureFromSurface(&m_renderer, surface);

        SDL_FreeSurface(surface);

        auto textSize = getTextSizeImpl(ttfFont, text);

        SDL_Rect textRect;
        textRect.w = textSize.get_width();
        textRect.h = textSize.get_height();
        textRect.x = r.get_x() + (r.get_width() - textSize.get_width()) / 2;
        textRect.y = r.get_y() + (r.get_height() - textSize.get_height()) / 2;

        auto sdlrect = Sdl2Helpers::toSDL(r);
        SDL_RenderSetClipRect(&m_renderer, &sdlrect);

        SDL_QueryTexture(texture, nullptr, nullptr, &textRect.w, &textRect.h);

        SDL_RenderCopy(&m_renderer, texture, nullptr, &textRect);
        SDL_DestroyTexture(texture);
        SDL_RenderSetClipRect(&m_renderer, nullptr);

        m_needToApply = true;
    }

    auto GraphicsSdl2Impl::getTextSize(const font& f,
                                       std::string_view text) const -> dimension
    {
        auto ttfFont = getFontFromCache(f, m_fontCache);
        return getTextSizeImpl(ttfFont, text);
    }

}