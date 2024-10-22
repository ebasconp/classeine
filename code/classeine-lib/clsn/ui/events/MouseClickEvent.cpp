// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/events/MouseClickEvent.h>

namespace clsn::ui::events
{
    using namespace clsn::draw;

    MouseClickEvent::MouseClickEvent(MouseClickStatus status, const Point& Point)
    : m_status{status}
    , m_point{Point}
    {
    }

    auto MouseClickEvent::getStatus() const noexcept -> MouseClickStatus
    {
        return m_status;
    }

    auto MouseClickEvent::getPoint() const noexcept -> const Point&
    {
        return m_point;
    }
}