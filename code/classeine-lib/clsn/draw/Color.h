#pragma once

namespace clsn::draw
{
    class Color final
    {
        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned char a;

    public:
        constexpr Color(int r, int g, int b);
        constexpr Color(int r, int g, int b, int a);
        explicit constexpr Color(int hexaCode);

        int getColor() const noexcept;
        int getRed() const noexcept;
        int getGreen() const noexcept;
        int getBlue() const noexcept;
        int getAlpha() const noexcept;
    };
}