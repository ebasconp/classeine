// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <string>

namespace clsn::draw
{
    class point final
    {
        int m_x;
        int m_y;

    public:
        point();
        point(int x, int y);

        [[nodiscard]] auto get_x() const noexcept -> int;
        [[nodiscard]] auto get_y() const noexcept -> int;

        auto operator==(const point& other) const noexcept -> bool;

        auto operator+(const point& other) const noexcept -> point;

        [[nodiscard]] auto to_string() const -> std::string;
    };
}