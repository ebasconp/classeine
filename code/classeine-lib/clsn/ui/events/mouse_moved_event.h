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

    class mouse_moved_event : public core::event
    {
        point m_position;

    public:
        explicit mouse_moved_event(const point& position);

        auto get_position() const noexcept -> const point&;
    };
}