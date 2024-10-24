// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/draw/region.h>

#include <clsn/core/strings.h>

namespace clsn::draw
{
    region::region(const point& position, const dimension& size)
    : m_position{position}
    , m_size{size}
    {
    }

    region::region(int x, int y, int width, int height)
    : region{point{x, y}, dimension{width, height}}
    {
    }

    auto region::get_position() const noexcept -> const point& { return m_position; }

    auto region::get_size() const noexcept -> const dimension& { return m_size; }

    auto region::get_x() const noexcept -> int { return m_position.get_x(); }
    auto region::get_y() const noexcept -> int { return m_position.get_y(); }

    int region::get_width() const noexcept { return m_size.get_width(); }
    int region::get_height() const noexcept { return m_size.get_height(); }

    auto region::operator+(const region& r) const noexcept -> region
    {
        return {get_x() + r.get_x(),
                get_y() + r.get_y(),
                get_width() + r.get_width(),
                get_height() + r.get_height()};
    }

    auto region::contains_point(const point& p) const noexcept -> bool
    {
        const auto px = p.get_x();
        const auto py = p.get_y();

        const auto tx = get_x();
        const auto ty = get_y();

        const auto height = get_height();
        const auto width = get_width();

        return px > tx && px < (tx + width)
            && py > ty && py < (ty + height);
    }

    auto region::to_string() const noexcept -> std::string
    {
        return clsn::core::strings::format("Region. Position: [{}], Size: [{}]",
                               m_position, m_size);
    }
}