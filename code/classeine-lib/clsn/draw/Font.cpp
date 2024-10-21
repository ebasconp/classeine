// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/draw/Font.h>

#include <tuple>

namespace clsn::draw
{
    Font::Font() : Font{"", FontStyle::regular, 0}
    {
    }

    auto Font::getName() const noexcept -> const std::string&
    {
        return m_name;
    }

    auto Font::getSize() const noexcept -> int
    {
        return m_size;
    }

    auto Font::getStyle() const noexcept -> FontStyle
    {
        return m_style;
    }

    auto Font::addSize(int size) const noexcept -> Font
    {
        return {m_name, m_style, m_size + size};
    }

    auto Font::operator==(const Font& other) const noexcept -> bool
    {
        return std::tie(m_name, m_style, m_size) ==
               std::tie(other.m_name, other.m_style, other.m_size);
    }
}