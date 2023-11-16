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

#define CLSN_PROPERTY_BODY(type, name) \
    public: void set##name(const type& value) { m_##name.set(value); }  \
    public: const type& get##name() const { return m_##name.get(); } \
    public: clsn::core::events::EventListenerHandle add##name##ChangedListener(const clsn::core::events::ValueChangedEventListener<type> & listener) { return m_##name.addValueChangedEventListener(listener); }

#define CLSN_PROPERTY(type, name) \
    private: clsn::core::Property<type> m_##name { #name }; \
    CLSN_PROPERTY_BODY(type, name)

#define CLSN_PROPERTY_VAL(type, name, initialValue) \
    private: clsn::core::Property<type> m_##name { #name, initialValue }; \
    CLSN_PROPERTY_BODY(type, name)

