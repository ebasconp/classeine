#pragma once

#include "border_renderer_helpers.h"

#include "clsn/ui/border_control.h"
#include "clsn/ui/graphics.h"
#include "clsn/ui/renderer_base.h"
#include "clsn/ui/ui_manager.h"

#include <clsn/draw/region.h>

namespace clsn::ui
{
    template <typename InnerControlType>
    class border_control;
}



namespace clsn::ui::renderers
{
    using namespace clsn::ui;

    template <typename InnerControlType>
    class border_control_renderer : public renderer_base
    {
    public:
        void paint(graphics& graphics,
               const region& a_region,
               const control& base_control) const override
        {
            auto& control = static_cast<const border_control<InnerControlType>&>(base_control);

            const auto& bc = control.get_actual_foreground_color();

            graphics.set_draw_color(color{50, 100, 120});
            graphics.draw_fill_rectangle(a_region);

            const auto size = control.get_size();

            border_renderer_helpers::draw_flat_border(
                graphics, a_region, bc, size);

            region control_region{
               {a_region.get_x() + size, a_region.get_y() + size},
               {a_region.get_width() - (size * 2),
                        a_region.get_height() - (size * 2)}};

            control.get().paint(graphics, control_region);
        }
    };
}