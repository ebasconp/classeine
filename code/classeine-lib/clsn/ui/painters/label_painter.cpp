// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/painters/label_painter.h>

#include <clsn/draw/Color.h>
#include <clsn/draw/Region.h>

#include <clsn/ui/captionable_control.h>
#include <clsn/ui/ui_manager.h>

namespace clsn::ui::painters
{
    using namespace clsn::draw;

    void label_painter::paint_label(graphics& gfx,
                     const Region& rgn,
                     const captionable_control& ctrl,
                     const painting_info& info)
    {
        if (!ctrl.isEnabled())
        {
            gfx.set_draw_color({192, 192, 192});
            gfx.draw_text(rgn + Region{1, 1, 0, 0},
                          ctrl.get_actual_font(),
                          ctrl.getCaption(),
                          info.horizontal_alignment,
                          info.vertical_alignment);
        }

        gfx.set_draw_color(ctrl.isEnabled()
                               ? ctrl.get_actual_foreground_color()
                               : ui_manager::get_instance().getColor(
                                     "Theme", "disabledForegroundColor"));

        gfx.draw_text(rgn,
                      ctrl.get_actual_font(),
                      ctrl.getCaption(),
                      info.horizontal_alignment,
                      info.vertical_alignment);
    }
}