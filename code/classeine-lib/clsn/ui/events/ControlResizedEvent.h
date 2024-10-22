// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/events/ControlEvent.h>

namespace clsn::ui::events
{
    class ControlResizedEvent : public ControlEvent
    {
        int m_width;
        int m_height;

    public:
        ControlResizedEvent(Control&, int width, int height);

        auto getWidth() const noexcept -> int;
        auto getHeight() const noexcept -> int;
    };
}