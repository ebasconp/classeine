// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

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

        auto to_gray() const noexcept -> color;
        auto to_gray_if(bool ) const noexcept -> color;
    };
}