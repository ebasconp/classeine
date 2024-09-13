// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "clsn/draw/region.h"

#include "clsn/ui/renderer_base.h"

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

    template <typename ContainerType>
    class container_renderer : public renderer_base
    {
    public:
        void paint(graphics& gfx,
                   const region& rgn,
                   const control& base_ctrl) const override
        {
            const auto& container =
                static_cast<const ContainerType&>(base_ctrl);

            const auto container_needs_repaint = container.needs_to_paint_the_container();
            if (container_needs_repaint)
            {
                gfx.set_draw_color(base_ctrl.get_actual_background_color());
                gfx.draw_fill_rectangle(rgn);
            }

            if (container.get_visible_count() == 0)
            {
                gfx.set_draw_color(container.get_actual_background_color());
                gfx.draw_fill_rectangle(rgn);
                return;
            }

            const auto margin = container.get_margin();
            const region shift_rgn{
                margin, margin, -(margin * 2), -(margin * 2)};

            const auto count = container.get_count();
            for (int i = 0; i < count; i++)
            {
                auto& control = container[i];
                if (!control.is_visible() || !control.is_invalidated())
                    continue;

                const region ctrl_rgn{
                    control.get_actual_position(),
                    control.get_actual_size()}; // ETOTODOcontrol.getBounds();

                control.paint(gfx, ctrl_rgn + shift_rgn);
                control.validate();
            }

            if (container_needs_repaint)
                container.validate();
        }
    };
}