// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/events/ActionEvent.h>

namespace clsn::ui::events
{
    ActionEvent::ActionEvent(Control& ctrl, const std::string& actionName)
    : ControlEvent{ctrl}
    , m_actionName{actionName}
    {
    }

    auto ActionEvent::getActionName() const -> const std::string&
    {
        return m_actionName;
    }
}
