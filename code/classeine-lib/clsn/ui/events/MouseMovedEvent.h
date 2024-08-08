#pragma once

#include "clsn/core/event.h"

#include "clsn/draw/point.h"

namespace clsn::ui::events
{
    using namespace clsn::draw;

    struct PointData
    {
        point position;
    };

    using MouseMovedEvent = clsn::core::event<PointData>;
}