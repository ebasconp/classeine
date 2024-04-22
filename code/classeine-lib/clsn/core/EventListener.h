#pragma once

#include <functional>

namespace clsn::core
{
    template <typename EventType>
    using EventListener = std::function<void(EventType&)>;
}