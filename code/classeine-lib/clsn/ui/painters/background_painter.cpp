#include "background_painter.h"

namespace clsn::ui::painters::background_painter
{
    using namespace clsn::draw;

    void paint_background(graphics& gfx, const region& rgn, const color& clr)
    {
        gfx.set_draw_color(clr);
        gfx.draw_fill_rectangle(rgn);
    }
}