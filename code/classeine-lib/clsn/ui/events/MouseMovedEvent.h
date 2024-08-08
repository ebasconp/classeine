#pragma once

#include "clsn/core/event.h"

#include "clsn/draw/Point.h"

namespace clsn::ui::events
{
    using namespace clsn::draw;

    struct PointData
    {
        Point position;
    };

    using MouseMovedEvent = clsn::core::event<PointData>;
}