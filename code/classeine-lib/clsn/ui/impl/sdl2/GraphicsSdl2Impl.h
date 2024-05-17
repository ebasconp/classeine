#pragma once

#include <string_view>

#include "clsn/draw/Font.h"

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
        Font m_currentFont;

    public:
        explicit GraphicsSdl2Impl(SDL_Renderer& renderer);

        void setDrawColor(const Color& c);
        void setFont(const Font& font);

        void drawLine(const Point& p1, const Point& p2) const;
        void drawFillRectangle(const Region& r) const;
        void drawText(const Region& r, std::string_view text) const;

        void clear();
        void apply();
    };
}