#pragma once

#include "clsn/ui/graphics.h"
#include "clsn/ui/renderer_base.h"

#include "clsn/ui/painters/background_painter.h"
#include "clsn/ui/painters/border_painter.h"

namespace clsn::ui
{
    template <typename InnerControlType>
    class padding_control;
}


namespace clsn::ui::renderers
{
    using namespace clsn::ui;

    template <typename InnerControlType>
    class padding_control_renderer : public renderer_base
    {
    public:
        void paint(graphics& gfx,
               const region& rgn,
               const control& base_ctrl) const override
        {
            auto& ctrl = static_cast<const padding_control<InnerControlType>&>(base_ctrl);

            const auto& bc = ctrl.get_actual_foreground_color();

            using namespace clsn::ui::painters;

            background_painter::paint_background(gfx, rgn, bc, ctrl.is_opaque());

            const auto size = ctrl.get_size();

            painters::border_painter::paint_flat_border(
                gfx, rgn, bc, size);

            ctrl.get_inner_control().paint(
                gfx, ctrl.get_inner_control().get_actual_bounds());
        }
    };
}