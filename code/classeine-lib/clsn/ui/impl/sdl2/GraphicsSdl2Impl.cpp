#include "GraphicsSdl2Impl.h"

#include "Sdl2Helpers.h"

#include "clsn/draw/Color.h"
#include "clsn/draw/Point.h"
#include "clsn/draw/Region.h"

#include "clsn/core/Panic.h"

#include <SDL2/SDL.h>
#include <SDL_ttf.h>

namespace clsn::ui::impl::sdl2
{
    using namespace clsn::draw;

    GraphicsSdl2Impl::GraphicsSdl2Impl(SDL_Renderer& renderer)
    : m_renderer{renderer}
    , m_currentFont{"", 0}
    {
    }

    void GraphicsSdl2Impl::setDrawColor(const Color& c)
    {
        SDL_SetRenderDrawColor(
            &m_renderer, c.getRed(), c.getGreen(), c.getBlue(), c.getAlpha());
    }

    void GraphicsSdl2Impl::setFont(const Font& font)
    {
        m_currentFont = font;
    }

    void GraphicsSdl2Impl::clear() { SDL_RenderClear(&m_renderer); }

    void GraphicsSdl2Impl::apply() { SDL_RenderPresent(&m_renderer); }

    void GraphicsSdl2Impl::drawLine(const Point& p1, const Point& p2) const
    {
        SDL_RenderDrawLine(
            &m_renderer, p1.getX(), p1.getY(), p2.getX(), p2.getY());
    }

    void GraphicsSdl2Impl::drawFillRectangle(const Region& r) const
    {
        SDL_Rect rect = Sdl2Helpers::toSDL(r);
        SDL_RenderFillRect(&m_renderer, &rect);
    }

    void GraphicsSdl2Impl::drawText(const Region& r,
                                    std::string_view text) const
    {
        TTF_Font* f = TTF_OpenFont("/usr/share/fonts/opentype/urw-base35/NimbusSans-Regular.otf", 24);
        if (!f)
        {
            clsn::core::Panic("Font not found");
            return;
        }

        SDL_Color textColor = { 255, 255, 255 };
        SDL_Surface* surface = TTF_RenderText_Solid(f, text.data(), textColor);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(&m_renderer, surface);
        SDL_FreeSurface(surface);

        int actualTextWidth, actualTextHeight;
        TTF_SizeText(f, text.data(), &actualTextWidth, &actualTextHeight);

        SDL_Rect textRect;
        textRect.w = actualTextWidth;
        textRect.h = actualTextHeight;
        textRect.x = r.getX() + (r.getWidth() - actualTextWidth) / 2;
        textRect.y = r.getY() + (r.getHeight() - actualTextHeight) / 2;

        SDL_QueryTexture(texture, nullptr, nullptr, &textRect.w, &textRect.h);

        SDL_RenderCopy(&m_renderer, texture, nullptr, &textRect);
        SDL_DestroyTexture(texture);
    }

}