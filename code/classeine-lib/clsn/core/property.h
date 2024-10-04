// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/core/event_listener_list.h>
#include <clsn/core/strings.h>
#include <clsn/core/value_changed_event.h>

#include <type_traits>
#include <variant>

namespace clsn::core
{
    /// @class property
    /// @brief Template class representing a property with an optional state change listener.
    ///
    /// The `property` class template manages a property's value and provides mechanisms
    /// to listen for changes to the property's value.
    /// @tparam T The type of the property value.
    /// @tparam HasValueChangedEventListener Indicates if the property has value change listeners.
    template <typename T, bool HasValueChangedEventListener>
    class property final
    {
        std::string m_name; ///< The name of the property.
        T m_value; ///< The value of the property.

        /// Listeners for value change events.
        std::conditional_t<HasValueChangedEventListener,
                           event_listener_list<value_changed_event<T>>,
                           std::monostate> m_value_changed_listeners;

    public:
        /// @brief Constructs a property with the specified name.
        ///
        /// @param name The name of the property.
        template <typename StringType>
        explicit property(StringType&& name)
            : m_name{std::forward<StringType>(name)}
        {
        }

        /// @brief Constructs a property with the specified name and initial value.
        ///
        /// @param name The name of the property.
        /// @param value The initial value of the property.
        template <typename StringType, typename ValueType>
        property(StringType&& name, ValueType&& value)
            : m_name{std::forward<StringType>(name)}
            , m_value{std::forward<ValueType>(value)}
        {
        }

        /// @brief Gets the name of the property.
        ///
        /// @return The name of the property.
        [[nodiscard]] auto get_name() const noexcept -> const std::string&
        {
            return m_name;
        }

        /// @brief Gets the value of the property.
        ///
        /// @return The value of the property.
        [[nodiscard]] auto get() const noexcept -> const T&
        {
            return m_value;
        }

        /// @brief Converts the property to a string representation.
        ///
        /// @return A string representing the property.
        [[nodiscard]] auto to_string() const -> std::string
        {
            return strings::format("Property. Name: [{}], Value: [{}]",
                                   m_name, m_value);
        }

        /// @brief Adds a listener for value change events.
        ///
        /// This method is enabled only if `HasValueChangedEventListener` is true.
        /// @param listener The listener to add.
        /// @return An identifier for the added listener.
        template <bool B = HasValueChangedEventListener,
                  std::enable_if_t<B, int> = 0>
        auto add_value_changed_listener(
            event_listener<value_changed_event<T>> listener) -> int
        {
            return m_value_changed_listeners.add(std::move(listener));
        }

        /// @brief Sets the value of the property.
        ///
        /// If the new value is different from the current value, notifies the listeners.
        /// @param newValue The new value to set.
        /// @return True if the value was changed, false otherwise.
        template <typename ValueType>
        auto set(ValueType&& newValue) -> bool
        {
            if (m_value == newValue)
                return false;

            if constexpr (HasValueChangedEventListener)
            {
                auto oldValue = std::move(m_value);
                m_value = newValue;
                value_changed_event<T> e{oldValue, m_value};
                m_value_changed_listeners.notify(e);
            }
            else
                m_value = std::forward<ValueType>(newValue);

            return true;
        }
    };
}

// Macros to declare properties in an easier way

/// @def CLSN_FULL_PROPERTY_IMPL
/// @brief Macro to declare full property getters and setters in the implementation.
#define CLSN_FULL_PROPERTY_IMPL(name, type)                                      \
public:                                                                          \
    void set_##name(const type& value) noexcept { m_##name.set(value); }         \
    auto get_##name() const noexcept -> const type& { return m_##name.get(); }   \
    auto add_##name##_changed_listener(                                          \
        const clsn::core::event_listener<clsn::core::value_changed_event<type>>& \
            listener) -> int                                                     \
    {                                                                            \
        return m_##name.add_value_changed_listener(listener);                    \
    }

/// @def CLSN_FULL_PROPERTY
/// @brief Macro to declare a full property with getters and setters.
#define CLSN_FULL_PROPERTY(name, type, withValueChangedListener)                 \
private:                                                                         \
    clsn::core::property<type, withValueChangedListener> m_##name{#name};        \
    CLSN_FULL_PROPERTY_IMPL(name, type)

/// @def CLSN_FULL_PROPERTY_WITH_DEFAULT_VALUE
/// @brief Macro to declare a full property with a default value.
#define CLSN_FULL_PROPERTY_WITH_DEFAULT_VALUE(name, type, withValueChangedListener, initialValue) \
private:                                                                         \
    clsn::core::property<type, withValueChangedListener> m_##name{               \
        #name, initialValue};                                                    \
    CLSN_FULL_PROPERTY_IMPL(name, type)

/// @def CLSN_FULL_BOOL_PROPERTY_IMPL
/// @brief Macro to declare full boolean property getters and setters in the implementation.
#define CLSN_FULL_BOOL_PROPERTY_IMPL(name)                                       \
public:                                                                          \
    void set_##name(bool value) noexcept { m_##name.set(value); }                \
    auto is_##name() const noexcept -> bool { return m_##name.get(); }           \
    auto add_##name##_changed_listener(                                          \
        const clsn::core::event_listener<clsn::core::value_changed_event<bool>>& \
            listener) -> int                                                     \
    {                                                                            \
        return m_##name.add_value_changed_listener(listener);                    \
    }

/// @def CLSN_FULL_BOOL_PROPERTY
/// @brief Macro to declare a full boolean property with getters and setters.
#define CLSN_FULL_BOOL_PROPERTY(name, withValueChangedListener)                  \
private:                                                                         \
    clsn::core::property<bool, withValueChangedListener> m_##name{#name};        \
    CLSN_FULL_BOOL_PROPERTY_IMPL(name)

/// @def CLSN_FULL_BOOL_PROPERTY_WITH_DEFAULT_VALUE
/// @brief Macro to declare a full boolean property with a default value.
#define CLSN_FULL_BOOL_PROPERTY_WITH_DEFAULT_VALUE(name, withValueChangedListener, initialValue) \
private:                                                                         \
    clsn::core::property<bool, withValueChangedListener> m_##name{               \
        #name, initialValue};                                                    \
    CLSN_FULL_BOOL_PROPERTY_IMPL(name)

/// @def CLSN_HEADER_PROPERTY_DECL
/// @brief Macro to declare property getters and setters in the header file.
#define CLSN_HEADER_PROPERTY_DECL(name, type)                                    \
public:                                                                          \
    void set_##name(const type& value) noexcept;                                 \
    auto get_##name() const noexcept -> const type&;                             \
    auto add_##name##_changed_listener(                                          \
    const clsn::core::event_listener<clsn::core::value_changed_event<type>>&     \
        listener) -> int;

/// @def CLSN_HEADER_PROPERTY
/// @brief Macro to declare a property in the header file.
#define CLSN_HEADER_PROPERTY(name, type, withValueChangedListener)               \
private:                                                                         \
    clsn::core::property<type, withValueChangedListener> m_##name{#name};        \
    CLSN_HEADER_PROPERTY_DECL(name, type)

/// @def CLSN_HEADER_PROPERTY_WITH_DEFAULT_VALUE
/// @brief Macro to declare a property with a default value in the header file.
#define CLSN_HEADER_PROPERTY_WITH_DEFAULT_VALUE(name, type, withValueChangedListener, initialValue) \
private:                                                                         \
    clsn::core::property<type, withValueChangedListener> m_##name{               \
        #name, initialValue};                                                    \
    CLSN_HEADER_PROPERTY_DECL(name, type)

/// @def CLSN_HEADER_BOOL_PROPERTY_DECL
/// @brief Macro to declare boolean property getters and setters in the header file.
#define CLSN_HEADER_BOOL_PROPERTY_DECL(name)                                     \
public:                                                                          \
    void set_##name(bool value) noexcept;                                        \
    auto is_##name() const noexcept -> bool;                                     \
    auto add_##name##_changed_listener(                                          \
        const clsn::core::event_listener<clsn::core::value_changed_event<bool>>& \
        listener) -> int;

/// @def CLSN_HEADER_BOOL_PROPERTY
/// @brief Macro to declare a boolean property in the header file.
#define CLSN_HEADER_BOOL_PROPERTY(name, withValueChangedListener)                \
private:                                                                         \
    clsn::core::property<bool, withValueChangedListener> m_##name{#name};        \
    CLSN_HEADER_BOOL_PROPERTY_DECL(name)

/// @def CLSN_HEADER_BOOL_PROPERTY_WITH_DEFAULT_VALUE
/// @brief Macro to declare a boolean property with a default value in the header file.
#define CLSN_HEADER_BOOL_PROPERTY_WITH_DEFAULT_VALUE(name, withValueChangedListener, initialValue)  \
private:                                                                         \
    clsn::core::property<bool, withValueChangedListener> m_##name{               \
        #name, initialValue};                                                    \
    CLSN_HEADER_BOOL_PROPERTY_DECL(name)

/// @def CLSN_CPP_PROPERTY
/// @brief Macro to implement property getters and setters in the source file.
#define CLSN_CPP_PROPERTY(className, name, type)                                 \
void className::set_##name(const type& value) noexcept { m_##name.set(value); }  \
auto className::get_##name() const noexcept -> const type& { return m_##name.get(); } \
auto className::add_##name##_changed_listener(                                   \
    const clsn::core::event_listener<clsn::core::value_changed_event<type>>&     \
        listener) -> int                                                         \
    {                                                                            \
        return m_##name.add_value_changed_listener(listener);                    \
    }

/// @def CLSN_CPP_BOOL_PROPERTY
/// @brief Macro to implement boolean property getters and setters in the source file.
#define CLSN_CPP_BOOL_PROPERTY(className, name)                                  \
void className::set_##name(bool value) noexcept { m_##name.set(value); }         \
auto className::is_##name() const noexcept -> bool { return m_##name.get(); }    \
auto className::add_##name##_changed_listener(                                   \
    const clsn::core::event_listener<clsn::core::value_changed_event<bool>>&     \
        listener) -> int                                                         \
    {                                                                            \
        return m_##name.add_value_changed_listener(listener);                    \
    }
