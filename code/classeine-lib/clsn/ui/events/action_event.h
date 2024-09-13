// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "clsn/ui/events/control_event.h"

namespace clsn::ui::events
{
    class action_event : public control_event
    {
        std::string m_action_name;

    public:
        explicit action_event(control& ctrl, const std::string& action_name);

        auto get_action_name() const -> const std::string&;
    };
}