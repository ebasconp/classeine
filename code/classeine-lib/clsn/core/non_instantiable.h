// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

namespace clsn::core
{
    /// @brief Base class to prevent instantiation of derived classes.
    ///
    /// The `non_instantiable` class is designed to prevent instances of any
    /// class that inherits from it. All members of classes derived from this
    /// class must be declared static.
    /// It serves as a base class for other utility classes that should not be
    /// instantiated.
    class non_instantiable
    {
    public:
        non_instantiable() = delete;
        non_instantiable(const non_instantiable&) = delete;
        non_instantiable(non_instantiable&&) = delete;

        auto operator=(const non_instantiable&) -> non_instantiable& = delete;
        auto operator=(non_instantiable&&) -> non_instantiable& = delete;
    };
};