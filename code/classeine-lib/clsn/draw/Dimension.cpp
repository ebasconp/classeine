// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "Dimension.h"

#include "clsn/core/Strings.h"

namespace clsn::draw
{
    Dimension::Dimension()
    : Dimension(0, 0)
    {
    }

    Dimension::Dimension(int width, int height)
    : m_width{width}
    , m_height{height}
    {
    }

    auto Dimension::getWidth() const noexcept -> int { return m_width; }

    auto Dimension::getHeight() const noexcept -> int { return m_height; }

    auto Dimension::operator==(const Dimension& other) const noexcept -> bool
    {
        return m_width == other.m_width && m_height == other.m_height;
    }

    auto Dimension::operator+(const Dimension& other) const noexcept -> Dimension
    {
        return { m_width + other.m_width, m_height + other.m_height };
    }

    auto Dimension::toString() const -> std::string
    {
        return clsn::core::Strings::format(
            "Dimension: [W: {}, H: {}]", m_width, m_height);
    }
}