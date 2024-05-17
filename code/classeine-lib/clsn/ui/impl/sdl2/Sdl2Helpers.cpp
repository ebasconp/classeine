#include "Sdl2Helpers.h"

#include "clsn/draw/Color.h"
#include "clsn/draw/Region.h"

namespace clsn::ui::impl::sdl2::Sdl2Helpers
{
    SDL_Rect toSDL(const Region& region)
    {
        SDL_Rect rect;
        rect.x = region.getX();
        rect.y = region.getY();
        rect.w = region.getWidth();
        rect.h = region.getHeight();

        return rect;
    }

    SDL_Color toSDL(const Color& color)
    {
        SDL_Color c;
        c.a = color.getAlpha();
        c.r = color.getRed();
        c.g = color.getGreen();
        c.b = color.getBlue();

        return c;
    }
}
