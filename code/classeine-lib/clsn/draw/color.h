#pragma once

namespace clsn::draw
{
    class color final
    {
        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned char a;

    public:
        color();
        color(int r, int g, int b);
        color(int r, int g, int b, int a);
        explicit color(int hexaCode);

        [[nodiscard]] auto get_color() const noexcept -> int;
        [[nodiscard]] auto get_red() const noexcept -> int;
        [[nodiscard]] auto get_green() const noexcept -> int;
        [[nodiscard]] auto get_blue() const noexcept -> int;
        [[nodiscard]] auto get_alpha() const noexcept -> int;

        auto operator==(const color& ) const noexcept -> bool;
    };
}