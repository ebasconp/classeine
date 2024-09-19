// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/core/event.h>

namespace clsn::core
{
    class empty_event : public event
    {
    public:
        empty_event() = default;
    };
}