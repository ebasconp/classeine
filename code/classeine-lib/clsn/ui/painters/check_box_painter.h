#pragma once

#include "clsn/ui/graphics.h"

#include "clsn/draw/forward.h"

namespace clsn::ui { class check_box; }

namespace clsn::ui::painters::check_box_painter
{
    using namespace clsn::draw;

    void paint_check_box(graphics& gfx, const region& rgn, const check_box& cb, int size);
}