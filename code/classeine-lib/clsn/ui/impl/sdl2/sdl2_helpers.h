#pragma once

#include <SDL2/SDL.h>

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