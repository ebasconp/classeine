// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/painters/BorderPainter.h>

#include <clsn/draw/Region.h>

namespace clsn::ui::painters
{
    using namespace clsn::draw;

    void BorderPainter::paintFlat(Graphics& gfx,
                        const Region& rgn,
                        const Color& clr,
                        int depth)
    {
        int px = rgn.getPosition().getX();
        int py = rgn.getPosition().getY();
        int pw = rgn.getSize().getWidth();
        int ph = rgn.getSize().getHeight();

        gfx.setDrawColor(clr);
        for (int i = 0; i < depth; i++)
        {
            gfx.drawRectangle({px, py, pw, ph});
            px++;
            py++;
            pw -= 2;
            ph -= 2;
        }
    }
}