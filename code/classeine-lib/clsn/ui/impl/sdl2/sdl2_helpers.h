// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <SDL.h>
#undef main

namespace clsn::draw
{
    class color;
    class region;
}

namespace clsn::ui::impl::sdl2::sdl2_helpers
{
    using namespace clsn::draw;

    SDL_Rect to_sdl(const region&);
    SDL_Color to_sdl(const color&);
}