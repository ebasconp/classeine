// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/layouts/xy_layout_constraint.h>

namespace clsn::ui::layouts
{
    using namespace clsn::draw;

    xy_layout_constraint::xy_layout_constraint(const draw::point& position)
    : m_position{position}
    {
    }

    auto xy_layout_constraint::get_position() const -> const draw::point&
    {
        return m_position;
    }

    void xy_layout_constraint::set_position(const draw::point& position)
    {
        m_position = position;
    }
}