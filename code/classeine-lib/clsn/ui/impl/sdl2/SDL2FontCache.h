// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/impl/sdl2/SDL2FontWrapper.h>

#include <clsn/draw/Font.h>

#include <SDL_ttf.h>

#include <optional>
#include <unordered_map>

namespace clsn::ui::impl::sdl2
{
    using optional_ttf_font_ref = std::optional<std::reference_wrapper<TTF_Font>>;

    class SDL2FontCache final
    {
        mutable std::unordered_map<clsn::draw::Font, SDL2FontWrapper> m_fonts;

    public:
        optional_ttf_font_ref getFont(const clsn::draw::Font& Font) const;
    };
}