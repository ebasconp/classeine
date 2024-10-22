// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/draw/Forward.h>

#include <clsn/core/NonInstantiable.h>

#include <SDL.h>

#undef main

namespace clsn::ui::impl::sdl2
{
    class SDL2Helpers : public core::NonInstantiable
    {
    public:
        static SDL_Rect toSDL(const clsn::draw::Region&);
        static SDL_Color toSDL(const clsn::draw::Color&);
    };

}