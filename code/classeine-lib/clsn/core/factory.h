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
    class factory
    {
        std::function<std::unique_ptr<BaseType>()> m_factory;

    public:
        template <typename DerivedType>
        auto set() -> factory&
        {
            m_factory = []() { return std::make_unique<DerivedType>(); };
            return *this;
        }

        auto operator()() const -> std::unique_ptr<BaseType>
        {
            return m_factory();
        }

        template <typename DerivedType>
        static auto make_factory() -> factory<BaseType>
        {
            auto _factory = factory<BaseType>{};
            return _factory.template set<DerivedType>();
        }
    };
}