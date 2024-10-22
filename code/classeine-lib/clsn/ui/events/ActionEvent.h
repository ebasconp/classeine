// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/events/ControlEvent.h>

namespace clsn::ui::events
{
    class ActionEvent : public ControlEvent
    {
        std::string m_actionName;

    public:
        explicit ActionEvent(Control& ctrl, const std::string& actionName);

        auto getActionName() const -> const std::string&;
    };
}