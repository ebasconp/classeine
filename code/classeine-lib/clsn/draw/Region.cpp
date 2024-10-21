// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "Region.h"

#include "clsn/core/Strings.h"

namespace clsn::draw
{
    Region::Region(const Point& position, const Dimension& size)
    : m_position{position}
    , m_size{size}
    {
    }

    Region::Region(int x, int y, int width, int height)
    : Region{Point{x, y}, Dimension{width, height}}
    {
    }

    auto Region::getPosition() const noexcept -> const Point& { return m_position; }

    auto Region::getSize() const noexcept -> const Dimension& { return m_size; }

    auto Region::getX() const noexcept -> int { return m_position.getX(); }
    auto Region::getY() const noexcept -> int { return m_position.getY(); }

    int Region::getWidth() const noexcept { return m_size.getWidth(); }
    int Region::getHeight() const noexcept { return m_size.getHeight(); }

    auto Region::operator+(const Region& r) const noexcept -> Region
    {
        return {getX() + r.getX(),
                getY() + r.getY(),
                getWidth() + r.getWidth(),
                getHeight() + r.getHeight()};
    }

    auto Region::containsPoint(const Point& p) const noexcept -> bool
    {
        const auto px = p.getX();
        const auto py = p.getY();

        const auto tx = getX();
        const auto ty = getY();

        const auto height = getHeight();
        const auto width = getWidth();

        return px > tx && px < (tx + width)
            && py > ty && py < (ty + height);
    }

    auto Region::toString() const noexcept -> std::string
    {
        return clsn::core::Strings::format("Region. Position: [{}], Size: [{}]",
                               m_position, m_size);
    }
}