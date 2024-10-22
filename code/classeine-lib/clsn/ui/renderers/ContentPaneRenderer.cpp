// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/renderers/ContentPaneRenderer.h>

#include <clsn/ui/DynamicContentPane.h>

#include <clsn/ui/painters/BackgroundPainter.h>

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

    void ContentPaneRenderer::paint(Graphics& gfx,
                              const Region& rgn,
                              const Control& ctrl) const
    {
        const auto& con_pane = static_cast<const ContentPane&>(ctrl);

        auto inner_ctrl = con_pane.getActualInnerControl();
        if (!inner_ctrl.hasValue())
        {
            const auto& clr = con_pane.getActualBackgroundColor();
            painters::BackgroundPainter::paint(gfx, rgn, clr);
            return;
        }

        inner_ctrl.getRef().paint(gfx, rgn);
    }
}
