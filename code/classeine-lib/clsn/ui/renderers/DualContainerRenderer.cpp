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
            graphics.setDrawColor(baseControl.get_actual_background_color());
            graphics.drawFillRectangle(region);
        }

        ContainerRenderer::paint(graphics, region, baseControl);
    }
}