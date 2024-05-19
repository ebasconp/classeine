#pragma once

#include <string_view>

#include "Sdl2FontCache.h"

struct SDL_Renderer;

namespace clsn::draw
{
    class Color;
    class Font;
    class Point;
    class Region;
}

namespace clsn::ui::impl::sdl2
{
    using namespace clsn::draw;

    class GraphicsSdl2Impl final
    {
        SDL_Renderer& m_renderer;
        Sdl2FontCache m_fontCache;

    public:
        explicit GraphicsSdl2Impl(SDL_Renderer& renderer);
        Sdl2FontCache& getFontCache() noexcept;
        const Sdl2FontCache& getFontCache() const noexcept;

        void setDrawColor(const Color& c);

        void drawLine(const Point& p1, const Point& p2) const;
        void drawFillRectangle(const Region& r) const;
        void drawText(const Region& r,
                      const Font& f,
                      const Color& c,
                      std::string_view text) const;

        void clear();
        void apply();
    };
}