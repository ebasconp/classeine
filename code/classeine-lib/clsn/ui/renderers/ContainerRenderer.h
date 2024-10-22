// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/draw/Region.h>

#include <clsn/ui/IRenderer.h>

namespace clsn::ui::renderers
{
    template <typename ContainerType>
    class ContainerRenderer : public IRenderer
    {
    public:
        void paint(Graphics& gfx,
                   const clsn::draw::Region& rgn,
                   const Control& base_ctrl) const override
        {
            const auto& Container =
                static_cast<const ContainerType&>(base_ctrl);

            const auto container_needs_repaint = Container.needsToPaintTheContainer();
            if (container_needs_repaint)
            {
                gfx.setDrawColor(Container.getActualBackgroundColor());
                gfx.drawFillRectangle(rgn);
            }

            if (Container.getVisibleCount() == 0)
            {
                gfx.setDrawColor(Container.getActualBackgroundColor());
                gfx.drawFillRectangle(rgn);
                return;
            }

            const auto margin = Container.getMargin();
            const clsn::draw::Region shift_rgn{
                margin, margin, -(margin * 2), -(margin * 2)};

            const auto count = Container.getCount();
            for (int i = 0; i < count; i++)
            {
                auto& Control = Container[i];
                if (!Control.isVisible() || !Control.isInvalidated())
                    continue;

                const draw::Region ctrl_rgn{
                    Control.getActualPosition(),
                    Control.getActualSize()}; // ETOTODOcontrol.getBounds();

                Control.paint(gfx, ctrl_rgn + shift_rgn);
                Control.validate();
            }

            if (container_needs_repaint)
                Container.validate();
        }
    };
}