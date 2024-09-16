// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "entity.h"

#include <utility>

namespace clsn::core
{
    template <typename Type>
    class entity_wrapper : public entity
    {
        Type m_value;

    public:
        template <typename TType>
        entity_wrapper(TType&& value)
        : m_value{std::forward<TType>(value)}
        {
        }

        auto get() const noexcept -> const Type& { return m_value; }
        auto get() noexcept -> Type& { return m_value; }
    };
}