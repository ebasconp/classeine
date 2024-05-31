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

        [[nodiscard]] auto getColor() const noexcept -> int;
        [[nodiscard]] auto getRed() const noexcept -> int;
        [[nodiscard]] auto getGreen() const noexcept -> int;
        [[nodiscard]] auto getBlue() const noexcept -> int;
        [[nodiscard]] auto getAlpha() const noexcept -> int;

        auto operator==(const Color& ) const noexcept -> bool;
    };
}