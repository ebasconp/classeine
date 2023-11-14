#pragma once

#include <clsn/core/events/EventListenerList.h>
#include <clsn/core/events/ValueChangedEventListener.h>

namespace clsn::core
{
    template <typename T>
    class Property final
    {
        std::string m_name;
        T m_value;

        events::EventListenerList<events::ValueChangedEventListener<T>> m_valueChangedListeners;

    public:
        template <typename TString, typename TValue>
        Property(TString&& name, TValue&& initialValue)
        : m_name{std::forward<TString>(name)}
        , m_value{std::forward<TValue>(initialValue)}
        {
        }

        template <typename TString>
        Property(TString&& name)
        : m_name{std::forward<TString>(name)}
        {
        }

        const std::string& getName() const noexcept
        {
            return m_name;
        }

        const T& get() const noexcept
        {
            return m_value;
        }

        template <typename TValue>
        bool set(TValue&& value)
        {
			if (m_value == value)
				return false;

            T oldValue = std::move(m_value);
            m_value = std::forward<TValue>(value);

            m_valueChangedListeners(m_name, oldValue, m_value);
			return true;
        }

        events::EventListenerHandle addValueChangedEventListener(const events::ValueChangedEventListener<T>& listener)
        {
            return m_valueChangedListeners.add(listener);
        }
    };
}