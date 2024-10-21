// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "graphics_sdl2_impl.h"

#include "sdl2_helpers.h"

#include "clsn/draw/Font.h"
#include "clsn/draw/Point.h"
#include "clsn/draw/Region.h"

#include "clsn/core/System.h"

#include <SDL.h>
#undef main
#include <SDL2_gfxPrimitives.h>

#include <SDL_ttf.h>
#include <clsn/draw/TextHorizontalAlignment.h>
#include <clsn/draw/TextVerticalAlignment.h>

namespace
{
    auto getFontFromCache(const clsn::draw::Font& Font,
                          const clsn::ui::impl::sdl2::sdl2_font_cache& fontCache)
        -> TTF_Font*
    {
        auto optionalRefFont = fontCache.getFont(Font);
        if (!optionalRefFont.has_value())
        {
            clsn::core::System::panic("Font not found: [{}]", Font.getName());
            return nullptr;
        }

        return &optionalRefFont.value().get();
    }

    auto getTextSizeImpl(TTF_Font* ttfFont, std::string_view text)
        -> clsn::draw::Dimension
    {
        int actualTextWidth, actualTextHeight;
        TTF_SizeText(ttfFont, text.data(), &actualTextWidth, &actualTextHeight);
        return {actualTextWidth, actualTextHeight};
    }

}

namespace clsn::ui::impl::sdl2
{
    using namespace clsn::draw;

    graphics_sdl2_impl::graphics_sdl2_impl(
            SDL_Renderer& renderer,
            const Dimension& size)
    : m_renderer{renderer}
    , m_draw_color{255, 255, 255}
    , m_needs_to_apply{false}
    {
        create_texture(size);
    }

    graphics_sdl2_impl::~graphics_sdl2_impl()
    {
        destroy_texture();
    }

    sdl2_font_cache& graphics_sdl2_impl::get_font_cache() noexcept
    {
        return m_font_cache;
    }

    const sdl2_font_cache& graphics_sdl2_impl::get_font_cache() const noexcept
    {
        return m_font_cache;
    }

    void graphics_sdl2_impl::resize(const Dimension& newSize)
    {
        destroy_texture();
        create_texture(newSize);
    }

    void graphics_sdl2_impl::destroy_texture()
    {
        if (m_texture != nullptr)
        {
            SDL_DestroyTexture(m_texture);
        }
    }

    void graphics_sdl2_impl::create_texture(const Dimension& newSize)
    {
        using namespace clsn::core;

        using namespace std::string_literals;

        m_texture = SDL_CreateTexture(
            &m_renderer,
            SDL_PIXELFORMAT_RGBA8888,
            SDL_TEXTUREACCESS_TARGET,
            newSize.getWidth(),
            newSize.getHeight());

        if (m_texture == nullptr)
        {
            SDL_Log("Error while creating texture: %s", SDL_GetError());
            SDL_DestroyRenderer(&m_renderer);
            System::panic("Error while creating texture: "s + SDL_GetError());
            return;
        }

        SDL_SetRenderTarget(&m_renderer, m_texture);
    }

    void graphics_sdl2_impl::set_draw_color(const Color& c) const
    {
        m_draw_color = c;

        SDL_SetRenderDrawColor(
            &m_renderer,
            static_cast<Uint8>(c.getRed()),
            static_cast<Uint8>(c.getGreen()),
            static_cast<Uint8>(c.getBlue()),
            static_cast<Uint8>(c.getAlpha()));
    }

    void graphics_sdl2_impl::clear() const
    {
        SDL_RenderClear(&m_renderer);
    }

    void graphics_sdl2_impl::apply() const
    {
        if (m_needs_to_apply)
        {
            SDL_SetRenderTarget(&m_renderer, nullptr);
            SDL_RenderClear(&m_renderer);
            SDL_RenderCopy(&m_renderer, m_texture, nullptr, nullptr);
            SDL_RenderPresent(&m_renderer);

            SDL_SetRenderTarget(&m_renderer, m_texture);

            m_needs_to_apply = false;
        }
    }

    void graphics_sdl2_impl::draw_line(const Point& p1, const Point& p2) const
    {
        SDL_RenderDrawLine(
            &m_renderer, p1.getX(), p1.getY(), p2.getX(), p2.getY());

        m_needs_to_apply = true;
    }

    void graphics_sdl2_impl::draw_rectangle(const Region& r) const
    {
        SDL_Rect rect = sdl2_helpers::to_sdl(r);
        SDL_RenderDrawRect(&m_renderer, &rect);

        m_needs_to_apply = true;
    }

    void graphics_sdl2_impl::draw_fill_circle(const Region& r) const
    {
        const auto cx = static_cast<short>(r.getX() + r.getWidth() / 2);
        const auto cy = static_cast<short>(r.getY() + r.getHeight() / 2);
        const auto rx = static_cast<short>(r.getWidth() / 2);
        const auto ry = static_cast<short>(r.getHeight() / 2);

        const auto rs = filledEllipseRGBA(&m_renderer, cx, cy, rx, ry,
            static_cast<Uint8>(m_draw_color.getRed()),
            static_cast<Uint8>(m_draw_color.getGreen()),
            static_cast<Uint8>(m_draw_color.getBlue()),
            255);

        if (rs == -1)
        {
            clsn::core::Console::debug(
                "Error on graphics_sdl2_impl::draw_fill_circle: {}",
                SDL_GetError());
        }

        m_needs_to_apply = true;
    }

    void graphics_sdl2_impl::draw_fill_rectangle(const Region& r) const
    {
        SDL_Rect rect = sdl2_helpers::to_sdl(r);
        SDL_RenderFillRect(&m_renderer, &rect);

        m_needs_to_apply = true;
    }

    void graphics_sdl2_impl::draw_text(const Region& r,
                                    const Font& Font,
                                    std::string_view text,
                                    [[maybe_unused]] TextHorizontalAlignment horizontal_alignment,
                                    [[maybe_unused]] TextVerticalAlignment vertical_alignment) const
    {
        auto ttfFont = getFontFromCache(Font, m_font_cache);
        SDL_Color textColor = sdl2_helpers::to_sdl(m_draw_color);

        SDL_Surface* surface =
            TTF_RenderText_Blended(ttfFont, text.data(), textColor);

        SDL_Texture* texture =
            SDL_CreateTextureFromSurface(&m_renderer, surface);

        SDL_FreeSurface(surface);

        auto text_size = getTextSizeImpl(ttfFont, text);

        int x = r.getX();
        int y = r.getY();

        switch (horizontal_alignment)
        {
            case TextHorizontalAlignment::left:   break;
            case TextHorizontalAlignment::center:  x += (r.getWidth() - text_size.getWidth()) / 2; break;
            case TextHorizontalAlignment::right: x += r.getWidth() - text_size.getWidth(); break;
        }

        switch (vertical_alignment)
        {
            case TextVerticalAlignment::top:   break;
            case TextVerticalAlignment::middle:  y += (r.getHeight() - text_size.getHeight()) / 2; break;
            case TextVerticalAlignment::bottom: y += r.getHeight() - text_size.getHeight(); break;
        }

        SDL_Rect textRect;
        textRect.w = text_size.getWidth();
        textRect.h = text_size.getHeight();
        textRect.x = x;
        textRect.y = y;

        auto sdlrect = sdl2_helpers::to_sdl(r);
        SDL_RenderSetClipRect(&m_renderer, &sdlrect);

        SDL_QueryTexture(texture, nullptr, nullptr, &textRect.w, &textRect.h);

        SDL_RenderCopy(&m_renderer, texture, nullptr, &textRect);
        SDL_DestroyTexture(texture);
        SDL_RenderSetClipRect(&m_renderer, nullptr);

        m_needs_to_apply = true;
    }

    auto graphics_sdl2_impl::get_text_size(const Font& f,
                                       std::string_view text) const -> Dimension
    {
        auto ttfFont = getFontFromCache(f, m_font_cache);
        return getTextSizeImpl(ttfFont, text);
    }

}