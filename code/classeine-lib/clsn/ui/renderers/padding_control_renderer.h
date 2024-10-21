// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "clsn/ui/graphics.h"
#include "clsn/ui/renderer_base.h"

#include "clsn/ui/painters/border_painter.h"

namespace clsn::ui
{
    template <typename InnerControlType>
    class padding_control;
}

namespace clsn::ui::renderers
{
    template <typename InnerControlType>
    class padding_control_renderer : public renderer_base
    {
    public:
        void paint(graphics& gfx,
               const clsn::draw::region& rgn,
               const control& base_ctrl) const override
        {
            auto& ctrl = static_cast<const padding_control<InnerControlType>&>(base_ctrl);

            const auto& bc = ctrl.get_actual_foreground_color();

            const auto size = ctrl.getSize();

            painters::border_painter::paint_flat_border(
                gfx, rgn, bc, size);

            ctrl.get_inner_control().paint(
                gfx, ctrl.get_inner_control().get_actual_bounds());
        }
    };
}