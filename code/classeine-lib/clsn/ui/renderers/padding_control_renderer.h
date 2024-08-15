#pragma once

#include "border_renderer_helpers.h"

#include "clsn/ui/graphics.h"
#include "clsn/ui/padding_control.h"
#include "clsn/ui/renderer_base.h"
#include "clsn/ui/ui_manager.h"

#include <clsn/draw/region.h>

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
        void paint(graphics& graphics,
               const region& a_region,
               const control& base_control) const override
        {
            auto& control = static_cast<const padding_control<InnerControlType>&>(base_control);

            const auto& bc = control.get_actual_foreground_color();

            graphics.set_draw_color(color{50, 100, 120});
            graphics.draw_fill_rectangle(a_region);

            const auto size = control.get_size();

            border_renderer_helpers::draw_flat_border(
                graphics, a_region, bc, size);

            control.get_inner_control().paint(
                graphics, control.get_inner_control().get_actual_bounds());
        }
    };
}