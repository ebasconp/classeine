// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "mouse_click_event.h"

namespace clsn::ui::events
{
    using namespace clsn::draw;

    mouse_click_event::mouse_click_event(mouse_click_status status, const Point& Point)
    : m_status{status}
    , m_point{Point}
    {
    }

    auto mouse_click_event::get_status() const noexcept -> mouse_click_status
    {
        return m_status;
    }

    auto mouse_click_event::get_point() const noexcept -> const Point&
    {
        return m_point;
    }
}