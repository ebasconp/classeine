// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/painters/BackgroundPainter.h>

namespace clsn::ui::painters
{
    using namespace clsn::draw;

    void BackgroundPainter::paint(Graphics& gfx, const Region& rgn, const Color& clr)
    {
        gfx.setDrawColor(clr);
        gfx.drawFillRectangle(rgn);
    }
}