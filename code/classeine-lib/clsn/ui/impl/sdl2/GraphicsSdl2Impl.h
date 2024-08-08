#pragma once

#include <string_view>

#include "clsn/core/entity.h"

#include "clsn/draw/color.h"
#include "clsn/draw/dimension.h"

#include "Sdl2FontCache.h"



struct SDL_Renderer;

namespace clsn::draw
{
    class font;
    class point;
    class region;
}

namespace clsn::ui::impl::sdl2
{
    using namespace clsn::draw;

    class GraphicsSdl2Impl final : public clsn::core::entity
    {
        SDL_Renderer& m_renderer;
        SDL_Texture* m_texture;

        Sdl2FontCache m_fontCache;

        mutable color m_drawColor;

        mutable bool m_needToApply;

    public:
        explicit GraphicsSdl2Impl(SDL_Renderer& renderer, const dimension& size);
        ~GraphicsSdl2Impl();

        Sdl2FontCache& getFontCache() noexcept;
        const Sdl2FontCache& getFontCache() const noexcept;

        void resize(const dimension& newSize);

        void setDrawColor(const color& c) const;

        void drawFillCircle(const region& r) const;
        void drawLine(const point& p1, const point& p2) const;
        void drawRectangle(const region& r) const;
        void drawFillRectangle(const region& r) const;
        void drawText(const region& r,
                      const font& f,
                      std::string_view text) const;

        auto getTextSize(const font& f, std::string_view text) const -> dimension;

        void clear() const;
        void apply() const;

    private:
        void destroyTexture();
        void createTexture(const dimension& newSize);
    };
}