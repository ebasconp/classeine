#pragma once

#include "empty.h"
#include "event_listener_list.h"
#include "strings.h"
#include "value_changed_event.h"

#include <type_traits>

namespace clsn::core
{
    template <typename T, bool HasValueChangedEventListener>
    class property final
    {
        std::string m_name;
        T m_value;
        std::conditional_t<HasValueChangedEventListener,
                         event_listener_list<value_changed_event<T>>,
                         empty> m_value_changed_listeners;

    public:
        template <typename StringType>
        explicit property(StringType&& name)
        : m_name{std::forward<StringType>(name)}
        {
        }

        template <typename StringType, typename ValueType>
        property(StringType&& name, ValueType&& value)
        : m_name{std::forward<StringType>(name)}
        , m_value{std::forward<ValueType>(value)}
        {
        }

        [[nodiscard]] auto get_name() const noexcept -> const std::string&
        {
            return m_name;
        }

        [[nodiscard]] auto get() const noexcept -> const T& { return m_value; }

        auto to_string() const -> std::string
        {
            return strings::format("Property. Name: [{}}], Value: [{}]",
                                   m_name, m_value);
        }

        template <bool B = HasValueChangedEventListener,
                  std::enable_if_t<B, int> = 0>
        auto add_value_changed_listener(
            event_listener<value_changed_event<T>> listener) -> int
        {
            return m_value_changed_listeners.add(std::move(listener));
        }

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

#define CLSN_PROPERTY_BODY(name, type)                                        \
public:                                                                       \
    void set_##name(const type& value) noexcept { m_##name.set(value); }       \
                                                                              \
public:                                                                       \
    auto get_##name() const noexcept -> const type&{ return m_##name.get(); }  \
                                                                              \
public:                                                                       \
    auto add_##name##_changed_listener(                                           \
        const clsn::core::event_listener<clsn::core::value_changed_event<type>>& \
            listener) -> int                                                  \
    {                                                                         \
        return m_##name.add_value_changed_listener(listener);                    \
    }

#define CLSN_PROPERTY(name, type, withValueChangedListener)               \
private:                                                                  \
    clsn::core::property<type, withValueChangedListener> m_##name{#name}; \
    CLSN_PROPERTY_BODY(name, type)

#define CLSN_PROPERTY_VAL(name, type, withValueChangedListener, initialValue) \
private:                                                                      \
    clsn::core::property<type, withValueChangedListener> m_##name{            \
        #name, initialValue};                                                 \
    CLSN_PROPERTY_BODY(name, type)
}

#define CLSN_BOOL_PROPERTY_BODY(name)                                        \
public:                                                                       \
    void set_##name(bool value) noexcept { m_##name.set(value); }       \
                                                                              \
public:                                                                       \
    auto is_##name() const noexcept -> bool { return m_##name.get(); }         \
                                                                              \
public:                                                                       \
    auto add_##name##_changed_listener(                                          \
        const clsn::core::event_listener<clsn::core::value_changed_event<bool>>& \
            listener) -> int                                                  \
    {                                                                         \
        return m_##name.add_value_changed_listener(listener);                 \
    }


#define CLSN_BOOL_PROPERTY(name, withValueChangedListener)               \
private:                                                                  \
    clsn::core::property<bool, withValueChangedListener> m_##name{#name}; \
    CLSN_BOOL_PROPERTY_BODY(name)

#define CLSN_BOOL_PROPERTY_VAL(name, withValueChangedListener, initialValue)  \
private:                                                                      \
    clsn::core::property<bool, withValueChangedListener> m_##name{            \
        #name, initialValue};                                                 \
    CLSN_BOOL_PROPERTY_BODY(name)
