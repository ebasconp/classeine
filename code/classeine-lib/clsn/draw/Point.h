// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <string>

namespace clsn::draw
{
    class Point final
    {
        int m_x;
        int m_y;

    public:
        Point();
        Point(int x, int y);

        [[nodiscard]] auto getX() const noexcept -> int;
        [[nodiscard]] auto getY() const noexcept -> int;

        auto operator==(const Point& other) const noexcept -> bool;

        auto operator+(const Point& other) const noexcept -> Point;

        [[nodiscard]] auto toString() const -> std::string;
    };
}