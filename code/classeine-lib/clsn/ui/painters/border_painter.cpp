// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "border_painter.h"

#include "clsn/draw/region.h"

namespace clsn::ui::painters::border_painter
{
    using namespace clsn::draw;

    void paint_flat_border(graphics& graphics,
                        const region& region,
                        const color& the_color,
                        int depth)
    {
        int px = region.get_position().get_x();
        int py = region.get_position().get_y();
        int pw = region.get_size().get_width();
        int ph = region.get_size().get_height();

        graphics.set_draw_color(the_color);
        for (int i = 0; i < depth; i++)
        {
            graphics.draw_rectangle({px, py, pw, ph});
            px++;
            py++;
            pw -= 2;
            ph -= 2;
        }
    }

}