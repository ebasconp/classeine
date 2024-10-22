// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <string_view>

#include "clsn/core/Entity.h"

#include "clsn/draw/Color.h"
#include "clsn/draw/Forward.h"

#include "SDL2FontCache.h"

struct SDL_Renderer;

namespace clsn::ui::impl::sdl2
{
    class GraphicsSDL2Impl final : public clsn::core::Entity
    {
        SDL_Renderer& m_renderer;
        SDL_Texture* m_texture;

        SDL2FontCache m_font_cache;

        mutable clsn::draw::Color m_draw_color;

        mutable bool m_needs_to_apply;

    public:
        explicit GraphicsSDL2Impl(SDL_Renderer& renderer, const clsn::draw::Dimension& size);
        ~GraphicsSDL2Impl() override;

        SDL2FontCache& getFontCache() noexcept;
        const SDL2FontCache& getFontCache() const noexcept;

        void resize(const clsn::draw::Dimension& newSize);

        void setDrawColor(const clsn::draw::Color& c) const;

        void drawFillCircle(const clsn::draw::Region& r) const;
        void drawLine(const clsn::draw::Point& p1, const clsn::draw::Point& p2) const;
        void drawRectangle(const clsn::draw::Region& r) const;
        void drawFillRectangle(const clsn::draw::Region& r) const;
        void drawText(const clsn::draw::Region& r,
                      const clsn::draw::Font& f,
                      std::string_view text,
                      clsn::draw::TextHorizontalAlignment,
                      clsn::draw::TextVerticalAlignment) const;

        auto getTextSize(const clsn::draw::Font& f, std::string_view text) const -> clsn::draw::Dimension;

        void clear() const;
        void apply() const;

    private:
        void destroyTexture();
        void createTexture(const clsn::draw::Dimension& newSize);
    };
}