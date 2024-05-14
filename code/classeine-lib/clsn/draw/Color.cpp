#include "Color.h"

namespace clsn::draw
{
    Color::Color(int r, int g, int b)
    : Color(r, g, b, 0xFF)
    {
    }

    Color::Color(int r, int g, int b, int a)
    : r{static_cast<unsigned char>(r)}
    , g{static_cast<unsigned char>(g)}
    , b{static_cast<unsigned char>(b)}
    , a{static_cast<unsigned char>(a)}
    {
    }

    Color::Color(int hexaCode)
    : Color((hexaCode & 0x00FF0000) >> 16,
            (hexaCode & 0x0000FF00) >> 8,
            (hexaCode & 0x000000FF),
            (hexaCode & 0xFF000000) >> 24)
    {
    }

    int Color::getColor() const noexcept
    {
        return a << 24 | r << 16 | g << 8 | b;
    }

    int Color::getRed() const noexcept { return r; }

    int Color::getGreen() const noexcept { return g; }

    int Color::getBlue() const noexcept { return b; }

    int Color::getAlpha() const noexcept { return a; }
}