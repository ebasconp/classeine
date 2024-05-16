#include "GraphicsSdl2Impl.h"

#include "clsn/draw/Color.h"
#include "clsn/draw/Point.h"
#include "clsn/draw/Region.h"

#include <SDL2/SDL.h>

namespace clsn::ui::impl::sdl2
{
    using namespace clsn::draw;

    GraphicsSdl2Impl::GraphicsSdl2Impl(SDL_Renderer& renderer)
    : m_renderer{renderer}
    {

    }

    void GraphicsSdl2Impl::setDrawColor(const Color& c)
    {
        SDL_SetRenderDrawColor(
            &m_renderer, c.getRed(), c.getGreen(), c.getBlue(),
            c.getAlpha());
    }

    void GraphicsSdl2Impl::clear()
    {
        SDL_RenderClear(&m_renderer);
    }

    void GraphicsSdl2Impl::apply()
    {
        SDL_RenderPresent(&m_renderer);
    }

    void GraphicsSdl2Impl::drawLine(const Point& p1, const Point& p2) const
    {
        SDL_RenderDrawLine(&m_renderer, p1.getX(), p1.getY(), p2.getX(), p2.getY());
    }

    void GraphicsSdl2Impl::drawFillRectangle(const Region& r) const
    {
        SDL_Rect rect{r.getX(), r.getY(), r.getWidth(), r.getHeight()};
        SDL_RenderFillRect(&m_renderer, &rect);
    }
}