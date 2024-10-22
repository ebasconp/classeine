// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/events/action_event.h>

namespace clsn::ui::events
{
    action_event::action_event(control& ctrl, const std::string& action_name)
    : control_event{ctrl}
    , m_action_name{action_name}
    {
    }

    auto action_event::get_action_name() const -> const std::string&
    {
        return m_action_name;
    }
}
