#include "sdl2_helpers.h"

#include "clsn/draw/color.h"
#include "clsn/draw/region.h"

namespace clsn::ui::impl::sdl2::sdl2_helpers
{
    SDL_Rect to_sdl(const region& region)
    {
        SDL_Rect rect;
        rect.x = region.get_x();
        rect.y = region.get_y();
        rect.w = region.get_width();
        rect.h = region.get_height();

        return rect;
    }

    SDL_Color to_sdl(const color& color)
    {
        SDL_Color c;
        c.a = color.get_alpha();
        c.r = color.get_red();
        c.g = color.get_green();
        c.b = color.get_blue();

        return c;
    }
}
