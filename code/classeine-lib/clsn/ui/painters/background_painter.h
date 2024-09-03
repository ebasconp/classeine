#pragma once

#include "clsn/ui/graphics.h"

#include "clsn/draw/forward.h"

namespace clsn::ui::painters::background_painter
{
    using namespace clsn::draw;

    void paint_background(graphics& gfx,
                          const region& rgn,
                          const color& clr,
                          bool opaque);
}