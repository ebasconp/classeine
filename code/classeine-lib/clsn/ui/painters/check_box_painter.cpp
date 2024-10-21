// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/painters/check_box_painter.h>

#include <clsn/ui/check_box.h>

#include <clsn/draw/region.h>

namespace clsn::ui::painters
{
    using namespace clsn::draw;
    
    void check_box_painter::paint_check_box(graphics& gfx, const region& r, const check_box& chk_box, int size)
    {
        const region rgn{
            {r.get_x() + (r.get_width() - size) / 2, r.get_y() + (r.get_height() - size) / 2},
            { size, size }
        };

        const auto enabled = chk_box.isEnabled();

        const color _color{0, 0, 255};
        gfx.set_draw_color(enabled ? _color : _color.to_gray());
        gfx.draw_rectangle(rgn);

        const auto x = rgn.get_x();
        const auto y = rgn.get_y();

        const auto bg_color = chk_box.is_pressed() ? color{224, 224, 224} : color{255, 255, 255};
        gfx.set_draw_color(bg_color);
        gfx.draw_fill_rectangle({x + 1, y + 1, size - 2, size - 2});

        if (chk_box.isChecked())
        {
            const color c1{0, 0, 128};
            gfx.set_draw_color(enabled ? c1 : c1.to_gray()); // Black color
            gfx.draw_rectangle({x + 2, y + 2, size - 4, size - 4});

            const color c2{0, 0, 192};
            gfx.set_draw_color(enabled ? c2 : c2.to_gray()); // Black color
            gfx.draw_rectangle({x + 3, y + 3, size - 6, size - 6});

            const color c3{0, 0, 255};
            gfx.set_draw_color(enabled ? c3 : c3.to_gray()); // Black color
            gfx.draw_fill_rectangle({x + 4, y + 4, size - 8, size - 8});
        }
    }
}