#include "GraphicsSdl2Impl.h"

#include "clsn/draw/Color.h"

#include <SDL2/SDL.h>

namespace clsn::ui::impl::sdl2
{
    GraphicsSdl2Impl::GraphicsSdl2Impl(SDL_Renderer& renderer)
    : m_renderer{renderer}
    {

    }

    void GraphicsSdl2Impl::setDrawColor(const clsn::draw::Color& c)
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
}