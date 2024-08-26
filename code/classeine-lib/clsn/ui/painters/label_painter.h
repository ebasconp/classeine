#pragma once

#include "clsn/ui/graphics.h"

#include "clsn/draw/forward.h"

namespace clsn::ui
{
    class control;
}

namespace clsn::ui::painters::label_painter
{
    using namespace clsn::draw;

    void paint_label(graphics& gfx, const region& rgn, const control& ctrl);
}