// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/core/System.h>

#include <functional>
#include <optional>

namespace clsn::core
{
    /// A class that encapsulates an optional reference to an object of type T.
    ///
    /// This class uses std::optional and std::reference_wrapper to manage
    /// optional references to objects.
    ///
    /// @tparam T The type of the object the reference will point to.
    template <typename T>
    class OptionalReference
    {
        std::optional<std::reference_wrapper<T>> m_value;

    public:
        /// Constructs an OptionalReference that holds a reference to the given object.
        ///
        /// @param value The object to hold a reference to.
        OptionalReference(T& value)
        : m_value{value}
        {
        }

        /// Default constructor that constructs an OptionalReference without a value.
        OptionalReference()
        : OptionalReference{std::nullopt}
        {
        }

        /// Constructs an OptionalReference without a value.
        ///
        /// @param nullopt A std::nullopt_t to initialize the OptionalReference without a value.
        OptionalReference(std::nullopt_t)
        : m_value{std::nullopt}
        {}

        /// Copy constructor.
        ///
        /// @param other Another OptionalReference to copy from.
        OptionalReference(const OptionalReference& other)
        {
            m_value = other.m_value;
        }

        /// Move constructor.
        ///
        /// @param other Another OptionalReference to move from.
        OptionalReference(OptionalReference&& other) noexcept
        {
            m_value = std::move(other.m_value);
        }

        /// Copy assignment operator.
        ///
        /// @param other Another OptionalReference to copy from.
        /// @return A reference to this OptionalReference.
        auto operator=(const OptionalReference& other) -> OptionalReference&
        {
            if (&other == this)
                return *this;

            m_value = other.m_value;
            return *this;
        }

        /// Move assignment operator.
        ///
        /// @param other Another OptionalReference to move from.
        /// @return A reference to this OptionalReference.
        auto operator=(OptionalReference&& other) noexcept -> OptionalReference&
        {
            if (&other == this)
                return *this;

            m_value = std::move(other.m_value);
            return *this;
        }

        /// Checks if the OptionalReference contains a value.
        ///
        /// @return true if the OptionalReference contains a value, false otherwise.
        [[nodiscard]] bool hasValue() const noexcept
        {
            return m_value.has_value();
        }

        /// Invokes the given procedure if the OptionalReference contains a value.
        ///
        /// @tparam Proc The type of the procedure to invoke.
        /// @param proc The procedure to invoke.
        /// @return The result of invoking the procedure, if the OptionalReference contains a value.
        template <typename Proc>
        auto safeInvoke(Proc proc)
        {
            if (hasValue())
                return proc(getRef());
        }

        /// Gets a reference to the value.
        ///
        /// @return A reference to the value.
        /// @throws System::panic if the OptionalReference does not contain a value.
        auto getRef() -> T&
        {
            if (!hasValue())
                System::panic("optional_reference_with_no_value");

            return m_value.value().get();
        }

        /// Gets a const reference to the value.
        ///
        /// @return A const reference to the value.
        /// @throws System::panic if the OptionalReference does not contain a value.
        auto getRef() const -> const T&
        {
            if (!hasValue())
                System::panic("OptionalReference with no value");

            return m_value.value().get();
        }

        /// Converts the current OptionalReference to an OptionalReference with a const reference.
        ///
        /// @return An OptionalReference<const T> with a const reference to the value.
        auto to_const() const -> OptionalReference<const T>
        {
            if (!hasValue())
                return {};

            return OptionalReference<const T>{getRef()};
        }

        /// Equality operator.
        ///
        /// @param other Another OptionalReference to compare with.
        /// @return true if both optional_references are equal, false otherwise.
        bool operator==(const OptionalReference& other) const
        {
            if (hasValue() != other.hasValue())
                return false;

            if (!hasValue())
                return true;

            return getRef() == other.getRef();
        }

        /// Inequality operator.
        ///
        /// @param other Another OptionalReference to compare with.
        /// @return true if both optional_references are not equal, false otherwise.
        bool operator!=(const OptionalReference& other) const
        {
            return !(*this == other);
        }
    };

    /// An alias for OptionalReference with a const reference.
    ///
    /// @tparam T The type of the object the reference will point to.
    template <typename T>
    using constOptionalReference = OptionalReference<const T>;
}