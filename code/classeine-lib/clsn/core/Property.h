// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/core/EventListenerList.h>
#include <clsn/core/Strings.h>
#include <clsn/core/ValueChangedEvent.h>

#include <type_traits>
#include <variant>

namespace clsn::core
{
    /// @class Property
    /// @brief Template class representing a Property with an optional state
    /// change listener.
    ///
    /// The `Property` class template manages a Property's value and provides
    /// mechanisms to listen for changes to the Property's value.
    /// @tparam T The type of the Property value.
    /// @tparam HasValueChangedEventListener Indicates if the Property has value
    /// change listeners.
    template <typename T, bool HasValueChangedEventListener>
    class Property final
    {
        std::string m_name; ///< The name of the Property.
        T m_value;          ///< The value of the Property.

        /// Listeners for value change events.
        std::conditional_t<HasValueChangedEventListener,
                           EventListenerList<ValueChangedEvent<T>>,
                           std::monostate>
            m_valueChangedListeners;

    public:
        /// @brief Constructs a Property with the specified name.
        ///
        /// @param name The name of the Property.
        template <typename StringType>
        explicit Property(StringType&& name)
        : m_name{std::forward<StringType>(name)}
        {
        }

        /// @brief Constructs a Property with the specified name and initial
        /// value.
        ///
        /// @param name The name of the Property.
        /// @param value The initial value of the Property.
        template <typename StringType, typename ValueType>
        Property(StringType&& name, ValueType&& value)
        : m_name{std::forward<StringType>(name)}
        , m_value{std::forward<ValueType>(value)}
        {
        }

        /// @brief Gets the name of the Property.
        ///
        /// @return The name of the Property.
        [[nodiscard]] auto getName() const noexcept -> const std::string&
        {
            return m_name;
        }

        /// @brief Gets the value of the Property.
        ///
        /// @return The value of the Property.
        [[nodiscard]] auto get() const noexcept -> const T& { return m_value; }

        /// @brief Converts the Property to a string representation.
        ///
        /// @return A string representing the Property.
        [[nodiscard]] auto toString() const -> std::string
        {
            return Strings::format(
                "Property. Name: [{}], Value: [{}]", m_name, m_value);
        }

        /// @brief Adds a listener for value change events.
        ///
        /// This method is enabled only if `HasValueChangedEventListener` is
        /// true.
        /// @param listener The listener to add.
        /// @return An identifier for the added listener.
        template <bool B = HasValueChangedEventListener,
                  std::enable_if_t<B, int> = 0>
        auto addValueChangedListener(
            EventListener<ValueChangedEvent<T>> listener) -> int
        {
            return m_valueChangedListeners.add(std::move(listener));
        }

        /// @brief Sets the value of the Property.
        ///
        /// If the new value is different from the current value, notifies the
        /// listeners.
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
                ValueChangedEvent<T> e{oldValue, m_value};
                m_valueChangedListeners.notify(e);
            }
            else
                m_value = std::forward<ValueType>(newValue);

            return true;
        }
    };
}

// Macros to declare properties in an easier way

/// @def CLSN_FULL_PROPERTY_IMPL
/// @brief Macro to declare full Property getters and setters in the
/// implementation.
#define CLSN_FULL_PROPERTY_IMPL(name, type)                                   \
public:                                                                       \
    void set##name(const type& value) noexcept                                \
    {                                                                         \
        m_property##name.set(value);                                          \
    }                                                                         \
    auto get##name() const noexcept -> const type&                            \
    {                                                                         \
        return m_property##name.get();                                        \
    }                                                                         \
    auto add##name##ChangedListener(                                          \
        const clsn::core::EventListener<clsn::core::ValueChangedEvent<type>>& \
            listener) -> int                                                  \
    {                                                                         \
        return m_property##name.addValueChangedListener(listener);            \
    }

/// @def CLSN_FULL_PROPERTY
/// @brief Macro to declare a full Property with getters and setters.
#define CLSN_FULL_PROPERTY(name, type, withValueChangedListener)           \
private:                                                                   \
    clsn::core::Property<type, withValueChangedListener> m_property##name{ \
        #name};                                                            \
    CLSN_FULL_PROPERTY_IMPL(name, type)

/// @def CLSN_FULL_PROPERTY_WITH_DEFAULT_VALUE
/// @brief Macro to declare a full Property with a default value.
#define CLSN_FULL_PROPERTY_WITH_DEFAULT_VALUE(                             \
    name, type, withValueChangedListener, initialValue)                    \
private:                                                                   \
    clsn::core::Property<type, withValueChangedListener> m_property##name{ \
        #name, initialValue};                                              \
    CLSN_FULL_PROPERTY_IMPL(name, type)

/// @def CLSN_FULL_BOOL_PROPERTY_IMPL
/// @brief Macro to declare full boolean Property getters and setters in the
/// implementation.
#define CLSN_FULL_BOOL_PROPERTY_IMPL(name)                                    \
public:                                                                       \
    void set##name(bool value) noexcept { m_property##name.set(value); }      \
    auto is##name() const noexcept -> bool { return m_property##name.get(); } \
    auto add##name##ChangedListener(                                          \
        const clsn::core::EventListener<clsn::core::ValueChangedEvent<bool>>& \
            listener) -> int                                                  \
    {                                                                         \
        return m_property##name.addValueChangedListener(listener);            \
    }

/// @def CLSN_FULL_BOOL_PROPERTY
/// @brief Macro to declare a full boolean Property with getters and setters.
#define CLSN_FULL_BOOL_PROPERTY(name, withValueChangedListener)            \
private:                                                                   \
    clsn::core::Property<bool, withValueChangedListener> m_property##name{ \
        #name};                                                            \
    CLSN_FULL_BOOL_PROPERTY_IMPL(name)

/// @def CLSN_FULL_BOOL_PROPERTY_WITH_DEFAULT_VALUE
/// @brief Macro to declare a full boolean Property with a default value.
#define CLSN_FULL_BOOL_PROPERTY_WITH_DEFAULT_VALUE(                        \
    name, withValueChangedListener, initialValue)                          \
private:                                                                   \
    clsn::core::Property<bool, withValueChangedListener> m_property##name{ \
        #name, initialValue};                                              \
    CLSN_FULL_BOOL_PROPERTY_IMPL(name)

/// @def CLSN_HEADER_PROPERTY_DECL
/// @brief Macro to declare Property getters and setters in the header file.
#define CLSN_HEADER_PROPERTY_DECL(name, type)                                 \
public:                                                                       \
    void set##name(const type& value) noexcept;                               \
    auto get##name() const noexcept -> const type&;                           \
    auto add##name##ChangedListener(                                          \
        const clsn::core::EventListener<clsn::core::ValueChangedEvent<type>>& \
            listener) -> int;

/// @def CLSN_HEADER_PROPERTY
/// @brief Macro to declare a Property in the header file.
#define CLSN_HEADER_PROPERTY(name, type, withValueChangedListener)         \
private:                                                                   \
    clsn::core::Property<type, withValueChangedListener> m_property##name{ \
        #name};                                                            \
    CLSN_HEADER_PROPERTY_DECL(name, type)

/// @def CLSN_HEADER_PROPERTY_WITH_DEFAULT_VALUE
/// @brief Macro to declare a Property with a default value in the header file.
#define CLSN_HEADER_PROPERTY_WITH_DEFAULT_VALUE(                           \
    name, type, withValueChangedListener, initialValue)                    \
private:                                                                   \
    clsn::core::Property<type, withValueChangedListener> m_property##name{ \
        #name, initialValue};                                              \
    CLSN_HEADER_PROPERTY_DECL(name, type)

/// @def CLSN_HEADER_BOOL_PROPERTY_DECL
/// @brief Macro to declare boolean Property getters and setters in the header
/// file.
#define CLSN_HEADER_BOOL_PROPERTY_DECL(name)                                  \
public:                                                                       \
    void set##name(bool value) noexcept;                                      \
    auto is##name() const noexcept -> bool;                                   \
    auto add##name##ChangedListener(                                          \
        const clsn::core::EventListener<clsn::core::ValueChangedEvent<bool>>& \
            listener) -> int;

/// @def CLSN_HEADER_BOOL_PROPERTY
/// @brief Macro to declare a boolean Property in the header file.
#define CLSN_HEADER_BOOL_PROPERTY(name, withValueChangedListener)          \
private:                                                                   \
    clsn::core::Property<bool, withValueChangedListener> m_property##name{ \
        #name};                                                            \
    CLSN_HEADER_BOOL_PROPERTY_DECL(name)

/// @def CLSN_HEADER_BOOL_PROPERTY_WITH_DEFAULT_VALUE
/// @brief Macro to declare a boolean Property with a default value in the
/// header file.
#define CLSN_HEADER_BOOL_PROPERTY_WITH_DEFAULT_VALUE(                      \
    name, withValueChangedListener, initialValue)                          \
private:                                                                   \
    clsn::core::Property<bool, withValueChangedListener> m_property##name{ \
        #name, initialValue};                                              \
    CLSN_HEADER_BOOL_PROPERTY_DECL(name)

/// @def CLSN_CPP_PROPERTY
/// @brief Macro to implement Property getters and setters in the source file.
#define CLSN_CPP_PROPERTY(className, name, type)                              \
    void className::set##name(const type& value) noexcept                     \
    {                                                                         \
        m_property##name.set(value);                                          \
    }                                                                         \
    auto className::get##name() const noexcept -> const type&                 \
    {                                                                         \
        return m_property##name.get();                                        \
    }                                                                         \
    auto className::add##name##ChangedListener(                               \
        const clsn::core::EventListener<clsn::core::ValueChangedEvent<type>>& \
            listener) -> int                                                  \
    {                                                                         \
        return m_property##name.addValueChangedListener(listener);            \
    }

/// @def CLSN_CPP_BOOL_PROPERTY
/// @brief Macro to implement boolean Property getters and setters in the source
/// file.
#define CLSN_CPP_BOOL_PROPERTY(className, name)                               \
    void className::set##name(bool value) noexcept                            \
    {                                                                         \
        m_property##name.set(value);                                          \
    }                                                                         \
    auto className::is##name() const noexcept -> bool                         \
    {                                                                         \
        return m_property##name.get();                                        \
    }                                                                         \
    auto className::add##name##ChangedListener(                               \
        const clsn::core::EventListener<clsn::core::ValueChangedEvent<bool>>& \
            listener) -> int                                                  \
    {                                                                         \
        return m_property##name.addValueChangedListener(listener);            \
    }
