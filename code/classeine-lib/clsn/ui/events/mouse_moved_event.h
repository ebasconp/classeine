#pragma once

#include "clsn/core/event.h"

#include "clsn/draw/point.h"

namespace clsn::ui::events
{
    using namespace clsn::draw;

    struct point_data
    {
        point position;
    };

    using mouse_moved_event = clsn::core::event<point_data>;
}