#pragma once

#include "Sdl2FontWrapper.h"

#include "clsn/draw/Font.h"
#include "clsn/draw/FontInfo.h"

#include <SDL_ttf.h>

#include <optional>
#include <string>
#include <unordered_map>
#include <utility>

namespace clsn::ui::impl::sdl2
{
    using namespace clsn::draw;

    using OptionalTTFFontRef = std::optional<std::reference_wrapper<TTF_Font>>;

    class Sdl2FontCache final
    {
        mutable std::unordered_map<Font, Sdl2FontWrapper> m_fonts;

    public:
        OptionalTTFFontRef getFont(const Font& font) const;
    };
}