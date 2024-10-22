// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/draw/forward.h>

#include <SDL.h>

#undef main

namespace clsn::ui::impl::sdl2::sdl2_helpers
{
    SDL_Rect to_sdl(const clsn::draw::region&);
    SDL_Color to_sdl(const clsn::draw::color&);
}