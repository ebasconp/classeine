#include "graphics_sdl2_impl.h"

#include "sdl2_helpers.h"

#include "clsn/draw/font.h"
#include "clsn/draw/point.h"
#include "clsn/draw/region.h"

#include "clsn/core/system.h"

#include <SDL.h>
#undef main
#include <SDL2_gfxPrimitives.h>

#include <SDL_ttf.h>
#include <clsn/draw/text_horizontal_alignment.h>
#include <clsn/draw/text_vertical_alignment.h>

namespace
{
    auto getFontFromCache(const clsn::draw::font& font,
                          const clsn::ui::impl::sdl2::sdl2_font_cache& fontCache)
        -> TTF_Font*
    {
        auto optionalRefFont = fontCache.get_font(font);
        if (!optionalRefFont.has_value())
        {
            clsn::core::system::panic("Font not found: [{}]", font.get_name());
            return nullptr;
        }

        return &optionalRefFont.value().get();
    }

    auto getTextSizeImpl(TTF_Font* ttfFont, std::string_view text)
        -> clsn::draw::dimension
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
            const dimension& size)
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

    void graphics_sdl2_impl::resize(const dimension& newSize)
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

    void graphics_sdl2_impl::create_texture(const dimension& newSize)
    {
        using namespace clsn::core;

        using namespace std::string_literals;

        m_texture = SDL_CreateTexture(
            &m_renderer,
            SDL_PIXELFORMAT_RGBA8888,
            SDL_TEXTUREACCESS_TARGET,
            newSize.get_width(),
            newSize.get_height());

        if (m_texture == nullptr)
        {
            SDL_Log("Error while creating texture: %s", SDL_GetError());
            SDL_DestroyRenderer(&m_renderer);
            system::panic("Error while creating texture: "s + SDL_GetError());
            return;
        }

        SDL_SetRenderTarget(&m_renderer, m_texture);
    }

    void graphics_sdl2_impl::set_draw_color(const color& c) const
    {
        m_draw_color = c;

        SDL_SetRenderDrawColor(
            &m_renderer,
            static_cast<Uint8>(c.get_red()),
            static_cast<Uint8>(c.get_green()),
            static_cast<Uint8>(c.get_blue()),
            static_cast<Uint8>(c.get_alpha()));
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

    void graphics_sdl2_impl::draw_line(const point& p1, const point& p2) const
    {
        SDL_RenderDrawLine(
            &m_renderer, p1.get_x(), p1.get_y(), p2.get_x(), p2.get_y());

        m_needs_to_apply = true;
    }

    void graphics_sdl2_impl::draw_rectangle(const region& r) const
    {
        SDL_Rect rect = sdl2_helpers::to_sdl(r);
        SDL_RenderDrawRect(&m_renderer, &rect);

        m_needs_to_apply = true;
    }

    void graphics_sdl2_impl::draw_fill_circle(const region& r) const
    {
        const auto cx = static_cast<short>(r.get_x() + r.get_width() / 2);
        const auto cy = static_cast<short>(r.get_y() + r.get_height() / 2);
        const auto rx = static_cast<short>(r.get_width() / 2);
        const auto ry = static_cast<short>(r.get_height() / 2);

        const auto rs = filledEllipseRGBA(&m_renderer, cx, cy, rx, ry,
            static_cast<Uint8>(m_draw_color.get_red()),
            static_cast<Uint8>(m_draw_color.get_green()),
            static_cast<Uint8>(m_draw_color.get_blue()),
            255);

        if (rs == -1)
        {
            clsn::core::console::debug(
                "Error on graphics_sdl2_impl::draw_fill_circle: {}",
                SDL_GetError());
        }

        m_needs_to_apply = true;
    }

    void graphics_sdl2_impl::draw_fill_rectangle(const region& r) const
    {
        SDL_Rect rect = sdl2_helpers::to_sdl(r);
        SDL_RenderFillRect(&m_renderer, &rect);

        m_needs_to_apply = true;
    }

    void graphics_sdl2_impl::draw_text(const region& r,
                                    const font& font,
                                    std::string_view text,
                                    [[maybe_unused]] text_horizontal_alignment horizontal_alignment,
                                    [[maybe_unused]] text_vertical_alignment vertical_alignment) const
    {
        auto ttfFont = getFontFromCache(font, m_font_cache);
        SDL_Color textColor = sdl2_helpers::to_sdl(m_draw_color);

        SDL_Surface* surface =
            TTF_RenderText_Blended(ttfFont, text.data(), textColor);

        SDL_Texture* texture =
            SDL_CreateTextureFromSurface(&m_renderer, surface);

        SDL_FreeSurface(surface);

        auto text_size = getTextSizeImpl(ttfFont, text);

        int x = r.get_x();
        int y = r.get_y();

        switch (horizontal_alignment)
        {
            case text_horizontal_alignment::left:   break;
            case text_horizontal_alignment::center:  x += (r.get_width() - text_size.get_width()) / 2; break;
            case text_horizontal_alignment::right: x += r.get_width() - text_size.get_width(); break;
        }

        switch (vertical_alignment)
        {
            case text_vertical_alignment::top:   break;
            case text_vertical_alignment::middle:  y += (r.get_height() - text_size.get_height()) / 2; break;
            case text_vertical_alignment::bottom: y += r.get_height() - text_size.get_height(); break;
        }

        SDL_Rect textRect;
        textRect.w = text_size.get_width();
        textRect.h = text_size.get_height();
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

    auto graphics_sdl2_impl::get_text_size(const font& f,
                                       std::string_view text) const -> dimension
    {
        auto ttfFont = getFontFromCache(f, m_font_cache);
        return getTextSizeImpl(ttfFont, text);
    }

}