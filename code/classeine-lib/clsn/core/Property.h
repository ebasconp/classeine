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
        std::conditional_t<HasValueChangedEventListener,
                         EventListenerList<ValueChangedEvent<T>>,
                         Empty> m_valueChangedListeners;

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

        [[nodiscard]] auto getName() const noexcept -> const std::string&
        {
            return m_name;
        }

        [[nodiscard]] auto get() const noexcept -> const T& { return m_value; }

        template <bool B = HasValueChangedEventListener,
                  std::enable_if_t<B, int> = 0>
        auto addValueChangedListener(
            EventListener<ValueChangedEvent<T>> listener) -> int
        {
            return m_valueChangedListeners.add(std::move(listener));
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
                ValueChangedEvent<T> e{oldValue, m_value};
                m_valueChangedListeners.notify(e);
            }
            else
                m_value = std::forward<ValueType>(newValue);

            return true;
        }
    };

#define CLSN_PROPERTY_BODY(name, type)                                        \
public:                                                                       \
    void set##name(const type& value) noexcept { m_##name.set(value); }       \
                                                                              \
public:                                                                       \
    auto get##name() const noexcept -> const type&{ return m_##name.get(); }  \
                                                                              \
public:                                                                       \
    auto add##name##ChangedListener(                                           \
        const clsn::core::EventListener<clsn::core::ValueChangedEvent<type>>& \
            listener) -> int                                                  \
    {                                                                         \
        return m_##name.addValueChangedListener(listener);                    \
    }

#define CLSN_PROPERTY(name, type, withValueChangedListener)               \
private:                                                                  \
    clsn::core::Property<type, withValueChangedListener> m_##name{#name}; \
    CLSN_PROPERTY_BODY(name, type)

#define CLSN_PROPERTY_VAL(name, type, withValueChangedListener, initialValue) \
private:                                                                      \
    clsn::core::Property<type, withValueChangedListener> m_##name{            \
        #name, initialValue};                                                 \
    CLSN_PROPERTY_BODY(name, type)
}

#define CLSN_BOOL_PROPERTY_BODY(name)                                        \
public:                                                                       \
    void set##name(bool value) noexcept { m_##name.set(value); }       \
                                                                              \
public:                                                                       \
    auto is##name() const noexcept -> bool { return m_##name.get(); }         \
                                                                              \
public:                                                                       \
    auto add##name##ChangedListener(                                          \
        const clsn::core::EventListener<clsn::core::ValueChangedEvent<bool>>& \
            listener) -> int                                                  \
    {                                                                         \
        return m_##name.addValueChangedListener(listener);                    \
    }


#define CLSN_BOOL_PROPERTY(name, withValueChangedListener)               \
private:                                                                  \
    clsn::core::Property<bool, withValueChangedListener> m_##name{#name}; \
    CLSN_BOOL_PROPERTY_BODY(name)

#define CLSN_BOOL_PROPERTY_VAL(name, withValueChangedListener, initialValue)  \
private:                                                                      \
    clsn::core::Property<bool, withValueChangedListener> m_##name{            \
        #name, initialValue};                                                 \
    CLSN_BOOL_PROPERTY_BODY(name)
