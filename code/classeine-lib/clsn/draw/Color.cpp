#include "Color.h"

#include <tuple>

namespace clsn::draw
{
    Color::Color()
    : Color(0x000000)
    {

    }

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

    auto Color::getColor() const noexcept -> int
    {
        return a << 24 | r << 16 | g << 8 | b;
    }

    auto Color::getRed() const noexcept -> int { return r; }

    auto Color::getGreen() const noexcept -> int { return g; }

    auto Color::getBlue() const noexcept -> int { return b; }

    int Color::getAlpha() const noexcept { return a; }

    auto Color::operator==(const Color& p) const noexcept -> bool
    {
        return std::tie(r, g, b, a) == std::tie(p.r, p.g, p.b, p.a);
    }
}