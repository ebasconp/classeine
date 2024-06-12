#pragma once

#include <SDL_ttf.h>


#include <memory>

namespace clsn::ui::impl::sdl2
{
    struct TTF_FontDeleter final
    {
        void operator()(TTF_Font* font) const
        {
            TTF_CloseFont(font);
        }
    };

    using Sdl2FontWrapper = std::unique_ptr<TTF_Font, TTF_FontDeleter>;
}