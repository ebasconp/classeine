// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/events/ControlEvent.h>

#include <clsn/ui/Control.h>

namespace clsn::ui::events
{
    ControlEvent::ControlEvent(Control& ctrl)
    : m_control{ctrl}
    {
    }

    auto ControlEvent::getControl() const -> const Control&
    {
        return m_control;
    }

    auto ControlEvent::getControl() -> Control&
    {
        return m_control;
    }
}
