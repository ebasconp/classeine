// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/core/Entity.h>

#include <utility>

namespace clsn::core
{
    template <typename Type>
    class EntityWrapper final : public Entity
    {
        Type m_value;

    public:
        template <typename TType>
        EntityWrapper(TType&& value)
        : m_value{std::forward<TType>(value)}
        {
        }

        auto get() const noexcept -> const Type& { return m_value; }
        auto get() noexcept -> Type& { return m_value; }
    };
}