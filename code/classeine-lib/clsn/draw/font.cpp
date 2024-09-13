// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "font.h"

#include <tuple>

namespace clsn::draw
{
    font::font() : font{"", font_style::regular, 0}
    {
    }

    auto font::get_name() const noexcept -> const std::string&
    {
        return m_name;
    }

    auto font::get_size() const noexcept -> int
    {
        return m_size;
    }

    auto font::get_style() const noexcept -> font_style
    {
        return m_style;
    }

    auto font::add_size(int size) const noexcept -> font
    {
        return {m_name, m_style, m_size + size};
    }

    auto font::operator==(const font& other) const noexcept -> bool
    {
        return std::tie(m_name, m_style, m_size) ==
               std::tie(other.m_name, other.m_style, other.m_size);
    }
}