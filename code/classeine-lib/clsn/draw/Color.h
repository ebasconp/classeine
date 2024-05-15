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
        Color();
        Color(int r, int g, int b);
        Color(int r, int g, int b, int a);
        explicit Color(int hexaCode);

        [[nodiscard]] int getColor() const noexcept;
        [[nodiscard]] int getRed() const noexcept;
        [[nodiscard]] int getGreen() const noexcept;
        [[nodiscard]] int getBlue() const noexcept;
        [[nodiscard]] int getAlpha() const noexcept;

        bool operator==(const Color& ) const noexcept;
    };
}