// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/core/Entity.h>

namespace clsn::core
{
    class Event : public Entity
    {
        bool m_consumed;

    public:
        ~Event() override = default;

        [[nodiscard]] auto isConsumed() const noexcept -> bool;

        void consume();

    protected:
        Event();
    };
}