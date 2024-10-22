// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/core/Event.h>

namespace clsn::ui
{
    class Control;
}

namespace clsn::ui::events
{
    class ControlEvent : public core::Event
    {
        Control& m_control;

    protected:
        explicit ControlEvent(Control& ctrl);

    public:
        auto getControl() const -> const Control&;
        auto getControl() -> Control&;
    };
}
