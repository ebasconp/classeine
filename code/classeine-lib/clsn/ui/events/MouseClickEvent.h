// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/core/Event.h>

#include <clsn/draw/Point.h>

namespace clsn::ui::events
{
    enum class MouseClickStatus
    {
        released,
        pressed
    };

    class MouseClickEvent : public core::Event
    {
        MouseClickStatus m_status;
        clsn::draw::Point m_point;

    public:
        MouseClickEvent(MouseClickStatus status, const clsn::draw::Point& Point);

        [[nodiscard]] auto getStatus() const noexcept -> MouseClickStatus;
        [[nodiscard]] auto getPoint() const noexcept -> const clsn::draw::Point&;
    };
}