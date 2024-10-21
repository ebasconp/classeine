// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "clsn/core/Event.h"

#include "clsn/draw/point.h"

namespace clsn::ui::events
{
    enum class mouse_click_status
    {
        released,
        pressed
    };

    class mouse_click_event : public core::Event
    {
        mouse_click_status m_status;
        clsn::draw::point m_point;

    public:
        mouse_click_event(mouse_click_status status, const clsn::draw::point& point);

        [[nodiscard]] auto get_status() const noexcept -> mouse_click_status;
        [[nodiscard]] auto get_point() const noexcept -> const clsn::draw::point&;
    };
}