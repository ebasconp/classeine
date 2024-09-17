// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/painters/radio_button_painter.h>

#include <clsn/ui/radio_button.h>

#include <clsn/draw/colors.h>
#include <clsn/draw/region.h>

namespace clsn::ui::painters::radio_button_painter
{
    using namespace clsn::draw;

    void paint_radio_button(graphics& gfx,
                            const region& r,
                            const radio_button& rd_btn,
                            int size)
    {
        const region rgn{{r.get_x() + (r.get_width() - size) / 2,
                          r.get_y() + (r.get_height() - size) / 2},
                         {size, size}};

        const auto x = rgn.get_x();
        const auto y = rgn.get_y();

        const auto is_enabled = rd_btn.is_enabled();

        gfx.set_draw_color(color{0, 0, 255}.to_gray_if(!is_enabled));
        gfx.draw_fill_circle({x, y, size, size});
        gfx.draw_fill_circle({x + 1, y + 1, size - 2, size - 2});

        const auto bg_color =
            rd_btn.is_pressed() ? color{224, 224, 224} : color{255, 255, 255};
        gfx.set_draw_color(bg_color);

        const auto white = colors::make_white();
        const bool is_checked = rd_btn.is_checked();

        gfx.set_draw_color(is_checked ? color{0, 0, 128}.to_gray_if(!is_enabled)
                                      : white); // Black color
        gfx.draw_fill_circle({x + 2, y + 2, size - 4, size - 4});

        gfx.set_draw_color(is_checked ? color{0, 0, 192}.to_gray_if(!is_enabled)
                                      : white); // Black color
        gfx.draw_fill_circle({x + 3, y + 3, size - 6, size - 6});

        gfx.set_draw_color(is_checked ? color{128, 255, 128}.to_gray_if(!is_enabled)
                                      : white); // Black color
        gfx.draw_fill_circle({x + 4, y + 4, size - 8, size - 8});
    }
}