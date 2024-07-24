#pragma once

#include <string_view>

#include "clsn/draw/Color.h"
#include "clsn/draw/Dimension.h"

#include "Sdl2FontCache.h"



struct SDL_Renderer;

namespace clsn::draw
{
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
        SDL_Texture* m_texture;

        Sdl2FontCache m_fontCache;

        mutable Color m_drawColor;

        mutable bool m_needToApply;

    public:
        explicit GraphicsSdl2Impl(SDL_Renderer& renderer, const Dimension& size);
        ~GraphicsSdl2Impl();

        Sdl2FontCache& getFontCache() noexcept;
        const Sdl2FontCache& getFontCache() const noexcept;

        void setDrawColor(const Color& c) const;

        void drawFillCircle(const Region& r) const;
        void drawLine(const Point& p1, const Point& p2) const;
        void drawRectangle(const Region& r) const;
        void drawFillRectangle(const Region& r) const;
        void drawText(const Region& r,
                      const Font& f,
                      std::string_view text) const;

        auto getTextSize(const Font& f, std::string_view text) const -> Dimension;

        void clear() const;
        void apply() const;
    };
}