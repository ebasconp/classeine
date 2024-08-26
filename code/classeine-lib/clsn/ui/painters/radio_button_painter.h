#pragma once

#include "clsn/ui/graphics.h"

#include "clsn/draw/forward.h"

namespace clsn::ui
{
    class radio_button;
}

namespace clsn::ui::painters::radio_button_painter
{
    using namespace clsn::draw;

    void paint_radio_button(graphics& gfx,
                            const region& rgn,
                            const radio_button& rb,
                            int size);
}