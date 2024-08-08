#pragma once

#include "event.h"

namespace clsn::core
{
    template <typename T>
    class value_changed
    {
        T m_old_value;
        const T& m_new_value;

    public:
        template <typename OldValueType>
        value_changed(OldValueType&& old_value, const T& new_value)
        : m_old_value{std::forward<OldValueType>(old_value)}
        , m_new_value{new_value}
        {
        }

        auto get_old_value() const noexcept -> const T& { return m_old_value; }
        auto get_new_value() const noexcept -> const T& { return m_new_value; }
    };

    template <typename T>
    using value_changed_event = event<value_changed<T>>;
}