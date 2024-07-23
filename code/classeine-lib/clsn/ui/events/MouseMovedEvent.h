#pragma once

#include "clsn/core/Event.h"

#include "clsn/draw/Point.h"

namespace clsn::ui::events
{
    using namespace clsn::draw;

    struct PointData
    {
        Point position;
    };

    using MouseMovedEvent = clsn::core::Event<PointData>;
}