// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/painters/CheckBoxPainter.h>

#include <clsn/ui/CheckBox.h>

#include <clsn/draw/Region.h>

namespace clsn::ui::painters
{
    using namespace clsn::draw;
    
    void CheckBoxPainter::paint(Graphics& gfx, const Region& r, const CheckBox& chk_box, int size)
    {
        const Region rgn{
            {r.getX() + (r.getWidth() - size) / 2, r.getY() + (r.getHeight() - size) / 2},
            { size, size }
        };

        const auto enabled = chk_box.isEnabled();

        const Color _color{0, 0, 255};
        gfx.setDrawColor(enabled ? _color : _color.toGray());
        gfx.drawRectangle(rgn);

        const auto x = rgn.getX();
        const auto y = rgn.getY();

        const auto bg_color = chk_box.isPressed() ? Color{224, 224, 224} : Color{255, 255, 255};
        gfx.setDrawColor(bg_color);
        gfx.drawFillRectangle({x + 1, y + 1, size - 2, size - 2});

        if (chk_box.isChecked())
        {
            const Color c1{0, 0, 128};
            gfx.setDrawColor(enabled ? c1 : c1.toGray()); // Black Color
            gfx.drawRectangle({x + 2, y + 2, size - 4, size - 4});

            const Color c2{0, 0, 192};
            gfx.setDrawColor(enabled ? c2 : c2.toGray()); // Black Color
            gfx.drawRectangle({x + 3, y + 3, size - 6, size - 6});

            const Color c3{0, 0, 255};
            gfx.setDrawColor(enabled ? c3 : c3.toGray()); // Black Color
            gfx.drawFillRectangle({x + 4, y + 4, size - 8, size - 8});
        }
    }
}