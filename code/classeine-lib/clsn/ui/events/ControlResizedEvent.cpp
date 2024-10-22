// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/events/ControlResizedEvent.h>

namespace clsn::ui::events
{

ControlResizedEvent::ControlResizedEvent(
    Control& ctrl, int width, int height)
: ControlEvent{ctrl}
, m_width{width}
, m_height{height}
{
}

auto ControlResizedEvent::getWidth() const noexcept -> int { return m_width; }
auto ControlResizedEvent::getHeight() const noexcept -> int { return m_height; }

}