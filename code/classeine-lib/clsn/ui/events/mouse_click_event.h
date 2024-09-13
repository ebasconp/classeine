// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "clsn/core/event.h"

#include "clsn/draw/point.h"

namespace clsn::ui::events
{
    using namespace clsn::draw;

    enum class mouse_click_status
    {
        released,
        pressed
    };

    class mouse_click_event : public core::event
    {
        mouse_click_status m_status;
        point m_point;

    public:
        mouse_click_event(mouse_click_status status, const point& point);

        [[nodiscard]] auto get_status() const noexcept -> mouse_click_status;
        [[nodiscard]] auto get_point() const noexcept -> const point&;
    };
}