#pragma once

struct SDL_Renderer;

namespace clsn::draw
{
    class Color;
}

namespace clsn::ui::impl::sdl2
{
    class GraphicsSdl2Impl final
    {
        SDL_Renderer& m_renderer;


    public:
        explicit GraphicsSdl2Impl(SDL_Renderer& renderer);

        void setDrawColor(const clsn::draw::Color& c);
        void clear();
        void apply();
    };
}