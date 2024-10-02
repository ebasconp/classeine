// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "content_pane_renderer.h"

#include "clsn/ui/dynamic_content_pane.h"

#include "clsn/ui/painters/background_painter.h"

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

    void content_pane_renderer::paint(graphics& gfx,
                              const region& rgn,
                              const control& ctrl) const
    {
        const auto& con_pane = static_cast<const content_pane&>(ctrl);

        auto inner_ctrl = con_pane.get_actual_inner_control();
        if (!inner_ctrl.has_value())
        {
            const auto& clr = con_pane.get_actual_background_color();
            painters::background_painter::paint_background(gfx, rgn, clr);
            return;
        }

        inner_ctrl.get_ref().paint(gfx, rgn);
    }
}
