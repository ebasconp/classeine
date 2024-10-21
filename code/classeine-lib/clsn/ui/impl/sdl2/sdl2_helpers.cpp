// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "sdl2_helpers.h"

#include "clsn/draw/Color.h"
#include "clsn/draw/Region.h"

namespace clsn::ui::impl::sdl2::sdl2_helpers
{
    using namespace clsn::draw;

    SDL_Rect to_sdl(const Region& Region)
    {
        SDL_Rect rect;
        rect.x = Region.getX();
        rect.y = Region.getY();
        rect.w = Region.getWidth();
        rect.h = Region.getHeight();

        return rect;
    }

    SDL_Color to_sdl(const Color& Color)
    {
        SDL_Color c;
        c.a = static_cast<Uint8>(Color.getAlpha());
        c.r = static_cast<Uint8>(Color.getRed());
        c.g = static_cast<Uint8>(Color.getGreen());
        c.b = static_cast<Uint8>(Color.getBlue());

        return c;
    }
}
