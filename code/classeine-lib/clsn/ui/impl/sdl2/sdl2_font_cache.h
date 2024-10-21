// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "sdl2_font_wrapper.h"

#include "clsn/draw/Font.h"

#include <SDL_ttf.h>

#include <optional>
#include <unordered_map>

namespace clsn::ui::impl::sdl2
{
    using optional_ttf_font_ref = std::optional<std::reference_wrapper<TTF_Font>>;

    class sdl2_font_cache final
    {
        mutable std::unordered_map<clsn::draw::Font, sdl2_font_wrapper> m_fonts;

    public:
        optional_ttf_font_ref getFont(const clsn::draw::Font& Font) const;
    };
}