// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/core/Event.h>

namespace clsn::core
{
    template <typename T>
    class ValueChangedEvent : public Event
    {
        T m_old_value;
        const T& m_new_value;

    public:
        template <typename OldValueType>
        ValueChangedEvent(OldValueType&& old_value, const T& new_value)
        : m_old_value{std::forward<OldValueType>(old_value)}
        , m_new_value{new_value}
        {
        }

        auto get_old_value() const noexcept -> const T& { return m_old_value; }
        auto get_new_value() const noexcept -> const T& { return m_new_value; }
    };
}