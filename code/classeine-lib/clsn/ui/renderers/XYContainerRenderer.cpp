#include "XYContainerRenderer.h"

namespace clsn::ui::renderers
{
    void XYContainerRenderer::paint(Graphics& graphics,
                                  const Region& region,
                                  const Control& baseControl) const
    {
        auto& container = static_cast<const XYContainer&>(baseControl);

        if (container.needsToPaintTheContainer())
        {
            graphics.setDrawColor(baseControl.getActualBackgroundColor());
            graphics.drawFillRectangle(region);
        }

        ContainerRenderer::paint(graphics, region, baseControl);
    }
}