#pragma once

#include <SDL2/SDL.h>

namespace clsn::draw
{
    class Color;
    class Region;
}

namespace clsn::ui::impl::sdl2::Sdl2Helpers
{
    using namespace clsn::draw;

    SDL_Rect toSDL(const Region&);
    SDL_Color toSDL(const Color&);
}