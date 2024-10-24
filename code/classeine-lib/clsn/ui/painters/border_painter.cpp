// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/painters/border_painter.h>

#include <clsn/draw/region.h>

namespace clsn::ui::painters
{
    using namespace clsn::draw;

    void border_painter::paint_flat_border(graphics& gfx,
                        const region& rgn,
                        const color& clr,
                        int depth)
    {
        int px = rgn.get_position().get_x();
        int py = rgn.get_position().get_y();
        int pw = rgn.get_size().get_width();
        int ph = rgn.get_size().get_height();

        gfx.set_draw_color(clr);
        for (int i = 0; i < depth; i++)
        {
            gfx.draw_rectangle({px, py, pw, ph});
            px++;
            py++;
            pw -= 2;
            ph -= 2;
        }
    }
}