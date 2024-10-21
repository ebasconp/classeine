// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "point.h"

#include <string>

#include "clsn/core/Strings.h"

namespace clsn::draw
{
    point::point()
    : point(0, 0)
    {
    }

    point::point(int x, int y)
    : m_x{x}
    , m_y{y}
    {
    }

    auto point::get_x() const noexcept -> int { return m_x; }

    auto point::get_y() const noexcept -> int { return m_y; }

    auto point::operator==(const point& other) const noexcept -> bool
    {
        return m_x == other.m_x && m_y == other.m_y;
    }

    auto point::operator+(const point& other) const noexcept -> point
    {
        return { m_x + other.m_x, m_y + other.m_y };
    }

    auto point::toString() const -> std::string
    {
        return clsn::core::Strings::format("Point: [{}, {}]", m_x, m_y);
    }
}