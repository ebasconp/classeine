#pragma once

#include <functional>

namespace clsn::core::events
{
    template <typename T>
    using ValueChangedEventListener = std::function<void(const T& oldValue, const T& newValue)>;
}