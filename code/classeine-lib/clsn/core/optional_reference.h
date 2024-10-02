// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/core/system.h>

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
    class optional_reference
    {
        std::optional<std::reference_wrapper<T>> m_value;

    public:
        /// Constructs an optional_reference that holds a reference to the given object.
        ///
        /// @param value The object to hold a reference to.
        optional_reference(T& value)
        : m_value{value}
        {
        }

        /// Default constructor that constructs an optional_reference without a value.
        optional_reference()
        : optional_reference{std::nullopt}
        {
        }

        /// Constructs an optional_reference without a value.
        ///
        /// @param nullopt A std::nullopt_t to initialize the optional_reference without a value.
        optional_reference(std::nullopt_t)
        : m_value{std::nullopt}
        {}

        /// Copy constructor.
        ///
        /// @param other Another optional_reference to copy from.
        optional_reference(const optional_reference& other)
        {
            m_value = other.m_value;
        }

        /// Move constructor.
        ///
        /// @param other Another optional_reference to move from.
        optional_reference(optional_reference&& other) noexcept
        {
            m_value = std::move(other.m_value);
        }

        /// Copy assignment operator.
        ///
        /// @param other Another optional_reference to copy from.
        /// @return A reference to this optional_reference.
        auto operator=(const optional_reference& other) -> optional_reference&
        {
            if (&other == this)
                return *this;

            m_value = other.m_value;
            return *this;
        }

        /// Move assignment operator.
        ///
        /// @param other Another optional_reference to move from.
        /// @return A reference to this optional_reference.
        auto operator=(optional_reference&& other) noexcept -> optional_reference&
        {
            if (&other == this)
                return *this;

            m_value = std::move(other.m_value);
            return *this;
        }

        /// Checks if the optional_reference contains a value.
        ///
        /// @return true if the optional_reference contains a value, false otherwise.
        [[nodiscard]] bool has_value() const noexcept
        {
            return m_value.has_value();
        }

        /// Invokes the given procedure if the optional_reference contains a value.
        ///
        /// @tparam Proc The type of the procedure to invoke.
        /// @param proc The procedure to invoke.
        /// @return The result of invoking the procedure, if the optional_reference contains a value.
        template <typename Proc>
        auto safe_invoke(Proc proc)
        {
            if (has_value())
                return proc(get_ref());
        }

        /// Gets a reference to the value.
        ///
        /// @return A reference to the value.
        /// @throws system::panic if the optional_reference does not contain a value.
        auto get_ref() -> T&
        {
            if (!has_value())
                system::panic("optional_reference_with_no_value");

            return m_value.value().get();
        }

        /// Gets a const reference to the value.
        ///
        /// @return A const reference to the value.
        /// @throws system::panic if the optional_reference does not contain a value.
        auto get_ref() const -> const T&
        {
            if (!has_value())
                system::panic("optional_reference_with_no_value");

            return m_value.value().get();
        }

        /// Converts the current optional_reference to an optional_reference with a const reference.
        ///
        /// @return An optional_reference<const T> with a const reference to the value.
        auto to_const() const -> optional_reference<const T>
        {
            if (!has_value())
                return {};

            return optional_reference<const T>{get_ref()};
        }

        /// Equality operator.
        ///
        /// @param other Another optional_reference to compare with.
        /// @return true if both optional_references are equal, false otherwise.
        bool operator==(const optional_reference& other) const
        {
            if (has_value() != other.has_value())
                return false;

            if (!has_value())
                return true;

            return get_ref() == other.get_ref();
        }

        /// Inequality operator.
        ///
        /// @param other Another optional_reference to compare with.
        /// @return true if both optional_references are not equal, false otherwise.
        bool operator!=(const optional_reference& other) const
        {
            return !(*this == other);
        }
    };

    /// An alias for optional_reference with a const reference.
    ///
    /// @tparam T The type of the object the reference will point to.
    template <typename T>
    using const_optional_reference = optional_reference<const T>;
}