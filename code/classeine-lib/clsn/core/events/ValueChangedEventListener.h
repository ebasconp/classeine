#pragma once

#include <functional>
#include <string>

namespace clsn::core::events
{
    template <typename T>
    using ValueChangedEventListener = std::function<void(const std::string& propertyName, const T& oldValue, const T& newValue)>;
}