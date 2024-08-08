#pragma once

#include "sdl2_font_wrapper.h"

#include "clsn/draw/font.h"

#include <SDL_ttf.h>

#include <optional>
#include <unordered_map>

namespace clsn::ui::impl::sdl2
{
    using namespace clsn::draw;

    using optional_ttf_font_ref = std::optional<std::reference_wrapper<TTF_Font>>;

    class sdl2_font_cache final
    {
        mutable std::unordered_map<font, sdl2_font_wrapper> m_fonts;

    public:
        optional_ttf_font_ref get_font(const font& font) const;
    };
}