#pragma once

#include <functional>

namespace clsn::core
{
    template <typename EventType>
    using event_listener = std::function<void(EventType&)>;
}