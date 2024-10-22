// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/layouts/XYLayoutConstraint.h>

namespace clsn::ui::layouts
{
    using namespace clsn::draw;

    XYLayoutConstraint::XYLayoutConstraint(const draw::Point& position)
    : m_position{position}
    {
    }

    auto XYLayoutConstraint::getPosition() const -> const draw::Point&
    {
        return m_position;
    }

    void XYLayoutConstraint::setPosition(const draw::Point& position)
    {
        m_position = position;
    }
}