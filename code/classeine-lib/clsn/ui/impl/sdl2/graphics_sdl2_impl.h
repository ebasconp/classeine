// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <string_view>

#include "clsn/core/entity.h"

#include "clsn/draw/color.h"
#include "clsn/draw/dimension.h"
#include <clsn/draw/text_horizontal_alignment.h>
#include <clsn/draw/text_vertical_alignment.h>

#include "sdl2_font_cache.h"

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

    class graphics_sdl2_impl final : public clsn::core::entity
    {
        SDL_Renderer& m_renderer;
        SDL_Texture* m_texture;

        sdl2_font_cache m_font_cache;

        mutable color m_draw_color;

        mutable bool m_needs_to_apply;

    public:
        explicit graphics_sdl2_impl(SDL_Renderer& renderer, const dimension& size);
        ~graphics_sdl2_impl();

        sdl2_font_cache& get_font_cache() noexcept;
        const sdl2_font_cache& get_font_cache() const noexcept;

        void resize(const dimension& newSize);

        void set_draw_color(const color& c) const;

        void draw_fill_circle(const region& r) const;
        void draw_line(const point& p1, const point& p2) const;
        void draw_rectangle(const region& r) const;
        void draw_fill_rectangle(const region& r) const;
        void draw_text(const region& r,
                      const font& f,
                      std::string_view text,
                      text_horizontal_alignment,
                      text_vertical_alignment) const;

        auto get_text_size(const font& f, std::string_view text) const -> dimension;

        void clear() const;
        void apply() const;

    private:
        void destroy_texture();
        void create_texture(const dimension& newSize);
    };
}