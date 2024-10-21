// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "dimension.h"

#include "clsn/core/Strings.h"

namespace clsn::draw
{
    dimension::dimension()
    : dimension(0, 0)
    {
    }

    dimension::dimension(int width, int height)
    : m_width{width}
    , m_height{height}
    {
    }

    auto dimension::get_width() const noexcept -> int { return m_width; }

    auto dimension::get_height() const noexcept -> int { return m_height; }

    auto dimension::operator==(const dimension& other) const noexcept -> bool
    {
        return m_width == other.m_width && m_height == other.m_height;
    }

    auto dimension::operator+(const dimension& other) const noexcept -> dimension
    {
        return { m_width + other.m_width, m_height + other.m_height };
    }

    auto dimension::toString() const -> std::string
    {
        return clsn::core::Strings::format(
            "Dimension: [W: {}, H: {}]", m_width, m_height);
    }
}