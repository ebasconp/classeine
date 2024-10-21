// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/core/Event.h>

namespace clsn::core
{
    class EmptyEvent : public Event
    {
    public:
        EmptyEvent() = default;
    };
}