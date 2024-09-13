// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <SDL_ttf.h>

#include <memory>

namespace clsn::ui::impl::sdl2
{
    struct ttf_font_deleter final
    {
        void operator()(TTF_Font* font) const
        {
            TTF_CloseFont(font);
        }
    };

    using sdl2_font_wrapper = std::unique_ptr<TTF_Font, ttf_font_deleter>;
}