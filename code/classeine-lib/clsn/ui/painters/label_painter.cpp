// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/painters/label_painter.h>

#include <clsn/draw/color.h>
#include <clsn/draw/region.h>

#include <clsn/ui/captionable_control.h>
#include <clsn/ui/ui_manager.h>

namespace clsn::ui::painters
{
    using namespace clsn::draw;

    void label_painter::paint_label(graphics& gfx,
                     const region& rgn,
                     const captionable_control& ctrl,
                     const painting_info& info)
    {
        if (!ctrl.is_enabled())
        {
            gfx.set_draw_color({192, 192, 192});
            gfx.draw_text(rgn + region{1, 1, 0, 0},
                          ctrl.get_actual_font(),
                          ctrl.get_caption(),
                          info.horizontal_alignment,
                          info.vertical_alignment);
        }

        gfx.set_draw_color(ctrl.is_enabled()
                               ? ctrl.get_actual_foreground_color()
                               : ui_manager::get_instance().get_color(
                                     "Theme", "disabledForegroundColor"));

        gfx.draw_text(rgn,
                      ctrl.get_actual_font(),
                      ctrl.get_caption(),
                      info.horizontal_alignment,
                      info.vertical_alignment);
    }
}