// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/core/Event.h>

namespace clsn::core
{
    Event::Event()
    : m_consumed{false}
    {
    }

    auto Event::isConsumed() const noexcept -> bool
    {
        return m_consumed;
    }

    void Event::consume()
    {
        m_consumed = true;
    }
}