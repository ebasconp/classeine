// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/Graphics.h>
#include <clsn/ui/IRenderer.h>

#include <clsn/ui/painters/BorderPainter.h>

namespace clsn::ui
{
    template <typename InnerControlType>
    class PaddingControl;
}

namespace clsn::ui::renderers
{
    template <typename InnerControlType>
    class PaddingControlRenderer : public IRenderer
    {
    public:
        void paint(Graphics& gfx,
               const clsn::draw::Region& rgn,
               const Control& base_ctrl) const override
        {
            auto& ctrl = static_cast<const PaddingControl<InnerControlType>&>(base_ctrl);

            const auto& bc = ctrl.getActualForegroundColor();

            const auto size = ctrl.getSize();

            painters::BorderPainter::paintFlat(
                gfx, rgn, bc, size);

            ctrl.getInnerControl().paint(
                gfx, ctrl.getInnerControl().getActualBounds());
        }
    };
}