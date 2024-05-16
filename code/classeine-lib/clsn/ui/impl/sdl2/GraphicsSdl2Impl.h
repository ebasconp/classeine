#pragma once

struct SDL_Renderer;

namespace clsn::draw
{
    class Color;
    class Point;
    class Region;
}

namespace clsn::ui::impl::sdl2
{
    using namespace clsn::draw;

    class GraphicsSdl2Impl final
    {
        SDL_Renderer& m_renderer;

    public:
        explicit GraphicsSdl2Impl(SDL_Renderer& renderer);

        void setDrawColor(const Color& c);

        void drawLine(const Point& p1, const Point& p2) const;
        void drawFillRectangle(const Region& r) const;


        void clear();
        void apply();
    };
}