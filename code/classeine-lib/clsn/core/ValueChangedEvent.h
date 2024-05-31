#pragma once

#include "Event.h"

namespace clsn::core
{
    template <typename T>
    class ValueChanged
    {
        T m_oldValue;
        const T& m_newValue;

    public:
        template <typename OldValueType>
        ValueChanged(OldValueType&& oldValue, const T& newValue)
        : m_oldValue{std::forward<OldValueType>(oldValue)}
        , m_newValue{newValue}
        {
        }

        auto getOldValue() const noexcept -> const T& { return m_oldValue; }
        auto getNewValue() const noexcept -> const T& { return m_newValue; }
    };

    template <typename T>
    using ValueChangedEvent = Event<ValueChanged<T>>;
}