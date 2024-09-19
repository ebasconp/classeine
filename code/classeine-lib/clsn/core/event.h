// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/core/entity.h>

namespace clsn::core
{
    class event : public entity
    {
        bool m_consumed;

    public:
        ~event() override = default;

        [[nodiscard]] auto is_consumed() const noexcept -> bool;

        void consume();

    protected:
        event();
    };
}