// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/draw/color.h>

#include <tuple>

namespace clsn::draw
{
    color::color()
    : color(0x000000)
    {

    }

    color::color(int r, int g, int b)
    : color(r, g, b, 0xFF)
    {
    }

    color::color(int r, int g, int b, int a)
    : r{static_cast<unsigned char>(r)}
    , g{static_cast<unsigned char>(g)}
    , b{static_cast<unsigned char>(b)}
    , a{static_cast<unsigned char>(a)}
    {
    }

    color::color(int hexaCode)
    : color((hexaCode & 0x00FF0000) >> 16,
            (hexaCode & 0x0000FF00) >> 8,
            (hexaCode & 0x000000FF),
            (hexaCode & 0xFF000000) >> 24)
    {
    }

    auto color::get_color() const noexcept -> int
    {
        return a << 24 | r << 16 | g << 8 | b;
    }

    auto color::get_red() const noexcept -> int { return r; }

    auto color::get_green() const noexcept -> int { return g; }

    auto color::get_blue() const noexcept -> int { return b; }

    int color::get_alpha() const noexcept { return a; }

    auto color::operator==(const color& p) const noexcept -> bool
    {
        return std::tie(r, g, b, a) == std::tie(p.r, p.g, p.b, p.a);
    }

    auto color::to_gray() const noexcept -> color
    {
        const auto gray =
            static_cast<int>((r * 0.299) + (g * 0.587) + (b * 0.114));

        return {gray, gray, gray};
    }

    auto color::to_gray_if(bool convert) const noexcept -> color
    {
        return convert ? to_gray() : *this;
    }
}