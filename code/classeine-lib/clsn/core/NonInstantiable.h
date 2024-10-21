// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

namespace clsn::core
{
    /// @brief Base class to prevent instantiation of derived classes.
    ///
    /// The `NonInstantiable` class is designed to prevent instances of any
    /// class that inherits from it. All members of classes derived from this
    /// class must be declared static.
    /// It serves as a base class for other utility classes that should not be
    /// instantiated.
    class NonInstantiable
    {
    public:
        NonInstantiable() = delete;
        NonInstantiable(const NonInstantiable&) = delete;
        NonInstantiable(NonInstantiable&&) = delete;

        auto operator=(const NonInstantiable&) -> NonInstantiable& = delete;
        auto operator=(NonInstantiable&&) -> NonInstantiable& = delete;
    };
};