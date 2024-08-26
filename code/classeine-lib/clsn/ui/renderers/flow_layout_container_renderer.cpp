#include "flow_layout_container_renderer.h"

namespace clsn::ui::renderers
{
    void flow_layout_container_renderer::paint(graphics& graphics,
                              const region& the_region,
                              const control& baseControl) const
    {
        const auto& container = static_cast<const flow_layout_container&>(baseControl);

        if (container.needs_to_paint_the_container())
        {
            graphics.set_draw_color(baseControl.get_actual_background_color());
            graphics.draw_fill_rectangle(the_region);
        }

        container_renderer::paint(graphics, the_region, baseControl);
    }
}