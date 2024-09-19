// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <<clsn/core/entity.h>

#include <functional>
#include <optional>

namespace clsn::core
{
    template <typename T>
    class lazy final : public entity
    {
        mutable std::optional<T> m_instance;
        std::function<T ()> m_factory;

    public:
        explicit lazy(std::function<T()> factory)
        : m_factory{factory}
        {
        }

        auto get() const -> const T&
        {
            if (!m_instance.has_value())
                m_instance = m_factory();

            return m_instance.value();
        }

        auto get() -> T&
        {
            if (!m_instance.has_value())
                m_instance = m_factory();

            return m_instance.value();
        }
    };
}