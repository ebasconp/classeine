// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/draw/Point.h>

#include <string>

#include <clsn/core/Strings.h>

namespace clsn::draw
{
    Point::Point()
    : Point(0, 0)
    {
    }

    Point::Point(int x, int y)
    : m_x{x}
    , m_y{y}
    {
    }

    auto Point::getX() const noexcept -> int { return m_x; }

    auto Point::getY() const noexcept -> int { return m_y; }

    auto Point::operator==(const Point& other) const noexcept -> bool
    {
        return m_x == other.m_x && m_y == other.m_y;
    }

    auto Point::operator+(const Point& other) const noexcept -> Point
    {
        return { m_x + other.m_x, m_y + other.m_y };
    }

    auto Point::toString() const -> std::string
    {
        return clsn::core::Strings::format("Point: [{}, {}]", m_x, m_y);
    }
}