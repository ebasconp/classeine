// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/painters/LabelPainter.h>

#include <clsn/draw/Color.h>
#include <clsn/draw/Region.h>

#include <clsn/ui/CaptionableControl.h>
#include <clsn/ui/UIManager.h>

namespace clsn::ui::painters
{
    using namespace clsn::draw;

    void LabelPainter::paint(Graphics& gfx,
                     const Region& rgn,
                     const CaptionableControl& ctrl,
                     const PaintingInfo& info)
    {
        if (!ctrl.isEnabled())
        {
            gfx.setDrawColor({192, 192, 192});
            gfx.drawText(rgn + Region{1, 1, 0, 0},
                          ctrl.getActualFont(),
                          ctrl.getCaption(),
                          info.horizontal_alignment,
                          info.vertical_alignment);
        }

        gfx.setDrawColor(ctrl.isEnabled()
                               ? ctrl.getActualForegroundColor()
                               : UIManager::get_instance().getColor(
                                     "Theme", "disabledForegroundColor"));

        gfx.drawText(rgn,
                      ctrl.getActualFont(),
                      ctrl.getCaption(),
                      info.horizontal_alignment,
                      info.vertical_alignment);
    }
}