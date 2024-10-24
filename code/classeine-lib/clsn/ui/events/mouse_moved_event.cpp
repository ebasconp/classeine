// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/events/mouse_moved_event.h>

namespace clsn::ui::events
{
    using namespace clsn::draw;

    mouse_moved_event::mouse_moved_event(const point& position)
    : m_position(position)
    {
    }

    auto mouse_moved_event::get_position() const noexcept -> const point&
    {
        return m_position;
    }
}