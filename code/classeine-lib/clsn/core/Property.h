#pragma once

#include "Empty.h"
#include "EventListenerList.h"
#include "ValueChangedEvent.h"

#include <type_traits>

namespace clsn::core
{
    template <typename T, bool HasValueChangedEventListener>
    class Property final
    {
        std::string m_name;
        T m_value;
        std::conditional<HasValueChangedEventListener,
                         EventListenerList<ValueChangedEvent<T>>,
                         Empty>::type m_valueChangedListeners;

    public:
        template <typename StringType>
        explicit Property(StringType&& name)
        : m_name{std::forward<StringType>(name)}
        {
        }

        template <typename StringType, typename ValueType>
        Property(StringType&& name, ValueType&& value)
        : m_name{std::forward<StringType>(name)}
        , m_value{std::forward<ValueType>(value)}
        {
        }

        const std::string& getName() const noexcept { return m_name; }

        const T& get() const noexcept { return m_value; }

        template <bool B = HasValueChangedEventListener,
                  typename std::enable_if<B, int>::type = 0>
        int addValueChangedListener(
            EventListener<ValueChangedEvent<T>> listener)
        {
            return m_valueChangedListeners.add(std::move(listener));
        }

        template <typename ValueType>
        bool set(ValueType&& newValue)
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

#define CLSN_PROPERTY_BODY(type, name)                                        \
public:                                                                       \
    void set##name(const type& value) noexcept { m_##name.set(value); }       \
                                                                              \
public:                                                                       \
    const type& get##name() const noexcept { return m_##name.get(); }         \
                                                                              \
public:                                                                       \
    int add##name##ChangedListener(               \
        const clsn::core::EventListener<clsn::core::ValueChangedEvent<type>>& \
            listener)                                                         \
    {                                                                         \
        return m_##name.addValueChangedListener(listener);                    \
    }

#define CLSN_PROPERTY(type, withValueChangedListener, name)               \
private:                                                                  \
    clsn::core::Property<type, withValueChangedListener> m_##name{#name}; \
    CLSN_PROPERTY_BODY(type, name)

#define CLSN_PROPERTY_VAL(type, withValueChangedListener, name, initialValue) \
private:                                                                      \
    clsn::core::Property<type, withValueChangedListener> m_##name{            \
        #name, initialValue};                                                 \
    CLSN_PROPERTY_BODY(type, name)
}