#pragma once

#include "event.h"

namespace clsn::core
{
    class empty_event : public event
    {
    public:
        empty_event() = default;
    };
}