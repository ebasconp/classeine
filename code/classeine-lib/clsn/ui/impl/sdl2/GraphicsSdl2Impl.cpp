#include "GraphicsSdl2Impl.h"

#include "Sdl2Helpers.h"

#include "clsn/ui/UIManager.h"

#include "clsn/draw/Color.h"
#include "clsn/draw/Font.h"
#include "clsn/draw/Point.h"
#include "clsn/draw/Region.h"

#include "clsn/core/Panic.h"

#include <SDL2/SDL.h>
#include <SDL_ttf.h>

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

    GraphicsSdl2Impl::GraphicsSdl2Impl(SDL_Renderer& renderer)
    : m_renderer{renderer}
    {
    }

    Sdl2FontCache& GraphicsSdl2Impl::getFontCache() noexcept
    {
        return m_fontCache;
    }

    const Sdl2FontCache& GraphicsSdl2Impl::getFontCache() const noexcept
    {
        return m_fontCache;
    }

    void GraphicsSdl2Impl::setDrawColor(const Color& c) const
    {
        SDL_SetRenderDrawColor(
            &m_renderer, c.getRed(), c.getGreen(), c.getBlue(), c.getAlpha());
    }

    void GraphicsSdl2Impl::clear() const { SDL_RenderClear(&m_renderer); }

    void GraphicsSdl2Impl::apply() const { SDL_RenderPresent(&m_renderer); }

    void GraphicsSdl2Impl::drawLine(const Point& p1, const Point& p2) const
    {
        SDL_RenderDrawLine(
            &m_renderer, p1.getX(), p1.getY(), p2.getX(), p2.getY());
    }

    void GraphicsSdl2Impl::drawRectangle(const Region& r) const
    {
        SDL_Rect rect = Sdl2Helpers::toSDL(r);
        SDL_RenderDrawRect(&m_renderer, &rect);
    }

    void GraphicsSdl2Impl::drawCircle(const Point& p, int diameter) const
    {
        // Circle test
        int circle_x = p.getX() + (diameter / 2);
        int circle_y = p.getY() + (diameter / 2);
        int circle_radius = diameter / 2;

        int point_x = 0;
        int point_y = circle_radius;
        int decision = 1 - circle_radius;

        while (point_y >= point_x)
        {
            // Symmetric points
            SDL_RenderDrawPoint(&m_renderer, circle_x + point_x, circle_y + point_y);
            SDL_RenderDrawPoint(&m_renderer, circle_x + point_y, circle_y + point_x);
            SDL_RenderDrawPoint(&m_renderer, circle_x - point_x, circle_y + point_y);
            SDL_RenderDrawPoint(&m_renderer, circle_x - point_y, circle_y + point_x);
            SDL_RenderDrawPoint(&m_renderer, circle_x + point_x, circle_y - point_y);
            SDL_RenderDrawPoint(&m_renderer, circle_x + point_y, circle_y - point_x);
            SDL_RenderDrawPoint(&m_renderer, circle_x - point_x, circle_y - point_y);
            SDL_RenderDrawPoint(&m_renderer, circle_x - point_y, circle_y - point_x);

            point_x++;

            if (decision < 0)
                decision += 2 * point_x + 1;
            else
            {
                point_y--;
                decision += 2 * (point_x - point_y) + 1;
            }
        }
    }

    void GraphicsSdl2Impl::drawFillRectangle(const Region& r) const
    {
        SDL_Rect rect = Sdl2Helpers::toSDL(r);
        SDL_RenderFillRect(&m_renderer, &rect);
    }

    void GraphicsSdl2Impl::drawText(const Region& r,
                                    const Font& font,
                                    const Color& color,
                                    std::string_view text) const
    {
        auto ttfFont = getFontFromCache(font, m_fontCache);
        SDL_Color textColor = Sdl2Helpers::toSDL(color);

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

        SDL_QueryTexture(texture, nullptr, nullptr, &textRect.w, &textRect.h);

        SDL_RenderCopy(&m_renderer, texture, nullptr, &textRect);
        SDL_DestroyTexture(texture);
    }

    auto GraphicsSdl2Impl::getTextSize(const Font& f,
                                       std::string_view text) const -> Dimension
    {
        auto ttfFont = getFontFromCache(f, m_fontCache);
        return getTextSizeImpl(ttfFont, text);
    }

}