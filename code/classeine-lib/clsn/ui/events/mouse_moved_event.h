// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "clsn/core/Event.h"

#include "clsn/draw/Point.h"

namespace clsn::ui::events
{
    class mouse_moved_event : public core::Event
    {
        clsn::draw::Point m_position;

    public:
        explicit mouse_moved_event(const clsn::draw::Point& position);

        auto getPosition() const noexcept -> const clsn::draw::Point&;
    };
}