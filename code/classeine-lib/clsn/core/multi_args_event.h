#pragma once

#include "Event.h"

#include <tuple>

namespace clsn::core
{
    template <typename... Args>
    using MultiArgsEvent = Event<std::tuple<Args...>>;
}