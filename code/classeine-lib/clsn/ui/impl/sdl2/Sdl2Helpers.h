#pragma once

#include <SDL2/SDL.h>

namespace clsn::draw
{
    class color;
    class region;
}

namespace clsn::ui::impl::sdl2::Sdl2Helpers
{
    using namespace clsn::draw;

    SDL_Rect toSDL(const region&);
    SDL_Color toSDL(const color&);
}