// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/core/event.h>

namespace clsn::core
{
    event::event()
    : m_consumed{false}
    {
    }

    auto event::is_consumed() const noexcept -> bool
    {
        return m_consumed;
    }

    void event::consume()
    {
        m_consumed = true;
    }
}