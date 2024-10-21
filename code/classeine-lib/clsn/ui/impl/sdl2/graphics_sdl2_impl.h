// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <string_view>

#include "clsn/core/Entity.h"

#include "clsn/draw/color.h"
#include "clsn/draw/forward.h"

#include "sdl2_font_cache.h"

struct SDL_Renderer;

namespace clsn::ui::impl::sdl2
{
    class graphics_sdl2_impl final : public clsn::core::Entity
    {
        SDL_Renderer& m_renderer;
        SDL_Texture* m_texture;

        sdl2_font_cache m_font_cache;

        mutable clsn::draw::color m_draw_color;

        mutable bool m_needs_to_apply;

    public:
        explicit graphics_sdl2_impl(SDL_Renderer& renderer, const clsn::draw::dimension& size);
        ~graphics_sdl2_impl() override;

        sdl2_font_cache& get_font_cache() noexcept;
        const sdl2_font_cache& get_font_cache() const noexcept;

        void resize(const clsn::draw::dimension& newSize);

        void set_draw_color(const clsn::draw::color& c) const;

        void draw_fill_circle(const clsn::draw::region& r) const;
        void draw_line(const clsn::draw::point& p1, const clsn::draw::point& p2) const;
        void draw_rectangle(const clsn::draw::region& r) const;
        void draw_fill_rectangle(const clsn::draw::region& r) const;
        void draw_text(const clsn::draw::region& r,
                      const clsn::draw::font& f,
                      std::string_view text,
                      clsn::draw::text_horizontal_alignment,
                      clsn::draw::text_vertical_alignment) const;

        auto get_text_size(const clsn::draw::font& f, std::string_view text) const -> clsn::draw::dimension;

        void clear() const;
        void apply() const;

    private:
        void destroy_texture();
        void create_texture(const clsn::draw::dimension& newSize);
    };
}