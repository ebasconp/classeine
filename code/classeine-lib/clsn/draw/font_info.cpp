// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/draw/font_info.h>

namespace clsn::draw
{
    font_info::font_info(std::string_view name, clsn::draw::font_style style)
    : m_name{name}
    , m_style{style}
    {
    }

    auto font_info::get_name() const noexcept -> const std::string&
    {
        return m_name;
    }

    auto font_info::get_style() const noexcept -> font_style { return m_style; }

    auto font_info::operator==(const clsn::draw::font_info& oth) const -> bool
    {
        if (this == &oth)
            return true;

        return m_name == oth.m_name && m_style == oth.m_style;
    }
}