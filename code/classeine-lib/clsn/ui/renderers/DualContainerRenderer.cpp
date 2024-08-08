#include "DualContainerRenderer.h"

namespace clsn::ui::renderers
{
    void DualContainerRenderer::paint(graphics& graphics,
                                  const region& region,
                                  const control& baseControl) const
    {
        auto& container = static_cast<const dual_container&>(baseControl);

        if (container.needs_to_paint_the_container())
        {
            graphics.set_draw_color(baseControl.get_actual_background_color());
            graphics.draw_fill_rectangle(region);
        }

        ContainerRenderer::paint(graphics, region, baseControl);
    }
}