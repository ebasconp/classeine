#pragma once

#include "clsn/ui/graphics.h"

#include "clsn/draw/forward.h"

namespace clsn::ui::painters::border_painter
{
    using namespace clsn::draw;

    void paint_flat_border(graphics& gfx,
                   const region& rgn,
                   const color& c,
                   int depth);
}