#include "DualContainerRenderer.h"

namespace clsn::ui::renderers
{
    void DualContainerRenderer::paint(Graphics& graphics,
                                  const Region& region,
                                  const Control& baseControl) const
    {
        auto& container = static_cast<const DualContainer&>(baseControl);

        if (container.needsToPaintTheContainer())
        {
            graphics.setDrawColor(baseControl.getActualBackgroundColor());
            graphics.drawFillRectangle(region);
        }

        ContainerRenderer::paint(graphics, region, baseControl);
    }
}