// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/painters/background_painter.h>

namespace clsn::ui::painters
{
    using namespace clsn::draw;

    void background_painter::paint_background(graphics& gfx, const Region& rgn, const Color& clr)
    {
        gfx.set_draw_color(clr);
        gfx.draw_fill_rectangle(rgn);
    }
}