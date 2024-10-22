// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/events/MouseMovedEvent.h>

namespace clsn::ui::events
{
    using namespace clsn::draw;

    MouseMovedEvent::MouseMovedEvent(const Point& position)
    : m_position(position)
    {
    }

    auto MouseMovedEvent::getPosition() const noexcept -> const Point&
    {
        return m_position;
    }
}