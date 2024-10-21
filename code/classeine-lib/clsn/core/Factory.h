// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <functional>
#include <memory>

namespace clsn::core
{
    template <typename BaseType>
    class Factory
    {
        std::function<std::unique_ptr<BaseType>()> m_factory;

    public:
        template <typename DerivedType>
        auto set() -> Factory&
        {
            m_factory = []() { return std::make_unique<DerivedType>(); };
            return *this;
        }

        auto operator()() const -> std::unique_ptr<BaseType>
        {
            return m_factory();
        }

        template <typename DerivedType>
        static auto makeFactory() -> Factory<BaseType>
        {
            auto _factory = Factory<BaseType>{};
            return _factory.template set<DerivedType>();
        }
    };
}