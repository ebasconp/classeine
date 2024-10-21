// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/painters/radio_button_painter.h>

#include <clsn/ui/radio_button.h>

#include <clsn/draw/Colors.h>
#include <clsn/draw/Region.h>

namespace clsn::ui::painters
{
    using namespace clsn::draw;

    void radio_button_painter::paint_radio_button(graphics& gfx,
                            const Region& r,
                            const radio_button& rd_btn,
                            int size)
    {
        const Region rgn{{r.getX() + (r.getWidth() - size) / 2,
                          r.getY() + (r.getHeight() - size) / 2},
                         {size, size}};

        const auto x = rgn.getX();
        const auto y = rgn.getY();

        const auto isEnabled = rd_btn.isEnabled();

        gfx.set_draw_color(Color{0, 0, 255}.toGrayIf(!isEnabled));
        gfx.draw_fill_circle({x, y, size, size});
        gfx.draw_fill_circle({x + 1, y + 1, size - 2, size - 2});

        const auto bg_color =
            rd_btn.is_pressed() ? Color{224, 224, 224} : Color{255, 255, 255};
        gfx.set_draw_color(bg_color);

        const auto white = Colors::makeWhite();
        const bool isChecked = rd_btn.isChecked();

        gfx.set_draw_color(isChecked ? Color{0, 0, 128}.toGrayIf(!isEnabled)
                                      : white); // Black Color
        gfx.draw_fill_circle({x + 2, y + 2, size - 4, size - 4});

        gfx.set_draw_color(isChecked ? Color{0, 0, 192}.toGrayIf(!isEnabled)
                                      : white); // Black Color
        gfx.draw_fill_circle({x + 3, y + 3, size - 6, size - 6});

        gfx.set_draw_color(isChecked ? Color{128, 255, 128}.toGrayIf(!isEnabled)
                                      : white); // Black Color
        gfx.draw_fill_circle({x + 4, y + 4, size - 8, size - 8});
    }
}