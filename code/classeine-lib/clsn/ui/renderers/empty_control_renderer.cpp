// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "empty_control_renderer.h"

#include "clsn/ui/control.h"

#include "clsn/ui/painters/background_painter.h"

namespace clsn::ui::renderers
{
    using namespace clsn::draw;
    using namespace clsn::ui;

    void empty_control_renderer::paint(graphics& gfx,
                              const region& rgn,
                              const control& ctrl) const
    {
        const auto& bc = ctrl.get_actual_background_color();

        painters::background_painter::paint_background(gfx, rgn, bc);
    }
}
