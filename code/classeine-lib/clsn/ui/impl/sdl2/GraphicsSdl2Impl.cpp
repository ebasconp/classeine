#include "GraphicsSdl2Impl.h"

#include "Sdl2Helpers.h"

#include "clsn/ui/UIManager.h"

#include "clsn/draw/Font.h"
#include "clsn/draw/Point.h"
#include "clsn/draw/Region.h"

#include "clsn/core/Panic.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#include <SDL_ttf.h>

#include <iostream> //ETOTODO: TO REMOVE

namespace
{
    auto getFontFromCache(const clsn::draw::Font& font,
                          const clsn::ui::impl::sdl2::Sdl2FontCache& fontCache)
        -> TTF_Font*
    {
        auto optionalRefFont = fontCache.getFont(font);
        if (!optionalRefFont.has_value())
        {
            clsn::core::Panic("Font not found");
            return nullptr;
        }

        return &optionalRefFont.value().get();
    }

    auto getTextSizeImpl(TTF_Font* ttfFont, std::string_view text)
        -> clsn::draw::Dimension
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
            const Dimension& size)
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

    void GraphicsSdl2Impl::resize(const Dimension& newSize)
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

    void GraphicsSdl2Impl::createTexture(const Dimension& newSize)
    {
        using namespace std::string_literals;

        m_texture = SDL_CreateTexture(
            &m_renderer,
            SDL_PIXELFORMAT_RGBA8888,
            SDL_TEXTUREACCESS_TARGET,
            newSize.getWidth(),
            newSize.getHeight());

        if (m_texture == nullptr)
        {
            SDL_Log("Error while creating texture: %s", SDL_GetError());
            SDL_DestroyRenderer(&m_renderer);
            Panic("Error while creating texture: "s + SDL_GetError());
            return;
        }

        SDL_SetRenderTarget(&m_renderer, m_texture);
    }

    void GraphicsSdl2Impl::setDrawColor(const Color& c) const
    {
        m_drawColor = c;

        SDL_SetRenderDrawColor(
            &m_renderer, c.getRed(), c.getGreen(), c.getBlue(), c.getAlpha());
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

    void GraphicsSdl2Impl::drawLine(const Point& p1, const Point& p2) const
    {
        SDL_RenderDrawLine(
            &m_renderer, p1.getX(), p1.getY(), p2.getX(), p2.getY());

        m_needToApply = true;
    }

    void GraphicsSdl2Impl::drawRectangle(const Region& r) const
    {
        SDL_Rect rect = Sdl2Helpers::toSDL(r);
        SDL_RenderDrawRect(&m_renderer, &rect);

        m_needToApply = true;
    }

    void GraphicsSdl2Impl::drawFillCircle(const Region& r) const
    {
        auto cx = static_cast<const short>(r.getX() + r.getWidth() / 2);
        auto cy = static_cast<const short>(r.getY() + r.getHeight() / 2);
        auto rx = static_cast<const short>(r.getWidth() / 2);
        auto ry = static_cast<const short>(r.getHeight() / 2);

        filledEllipseRGBA(&m_renderer, cx, cy, rx, ry, m_drawColor.getRed(), m_drawColor.getGreen(), m_drawColor.getBlue(), 255);

        m_needToApply = true;
    }

    void GraphicsSdl2Impl::drawFillRectangle(const Region& r) const
    {
        SDL_Rect rect = Sdl2Helpers::toSDL(r);
        SDL_RenderFillRect(&m_renderer, &rect);

        m_needToApply = true;
    }

    void GraphicsSdl2Impl::drawText(const Region& r,
                                    const Font& font,
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
        textRect.w = textSize.getWidth();
        textRect.h = textSize.getHeight();
        textRect.x = r.getX() + (r.getWidth() - textSize.getWidth()) / 2;
        textRect.y = r.getY() + (r.getHeight() - textSize.getHeight()) / 2;

        auto sdlrect = Sdl2Helpers::toSDL(r);
        SDL_RenderSetClipRect(&m_renderer, &sdlrect);

        SDL_QueryTexture(texture, nullptr, nullptr, &textRect.w, &textRect.h);

        SDL_RenderCopy(&m_renderer, texture, nullptr, &textRect);
        SDL_DestroyTexture(texture);
        SDL_RenderSetClipRect(&m_renderer, nullptr);

        m_needToApply = true;
    }

    auto GraphicsSdl2Impl::getTextSize(const Font& f,
                                       std::string_view text) const -> Dimension
    {
        auto ttfFont = getFontFromCache(f, m_fontCache);
        return getTextSizeImpl(ttfFont, text);
    }

}