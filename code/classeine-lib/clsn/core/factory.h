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
        factory& set()
        {
            m_factory = []() { return std::make_unique<DerivedType>(); };
            return *this;
        }

        std::unique_ptr<BaseType> operator()() const
        {
            return m_factory();
        }
    };


    template <typename BaseType, typename DerivedType>
    factory<BaseType> make_factory()
    {
        auto a_factory = factory<BaseType>{};
        return a_factory.template set<DerivedType>();
    }
}