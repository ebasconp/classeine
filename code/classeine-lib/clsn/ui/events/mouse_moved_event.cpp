// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "mouse_moved_event.h"

namespace clsn::ui::events
{
    using namespace clsn::draw;

    mouse_moved_event::mouse_moved_event(const Point& position)
    : m_position(position)
    {
    }

    auto mouse_moved_event::getPosition() const noexcept -> const Point&
    {
        return m_position;
    }
}