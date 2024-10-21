// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/core/Entity.h>

#include <functional>
#include <optional>

namespace clsn::core
{
    template <typename T>
    class Lazy final : public Entity
    {
        mutable std::optional<T> m_instance;
        std::function<T ()> m_factory;

    public:
        explicit Lazy(std::function<T()> Factory)
        : m_factory{Factory}
        {
        }

        auto get() const -> const T&
        {
            if (!m_instance.hasValue())
                m_instance = m_factory();

            return m_instance.value();
        }

        auto get() -> T&
        {
            if (!m_instance.hasValue())
                m_instance = m_factory();

            return m_instance.value();
        }
    };
}