#include "HBoxContainerRenderer.h"

#include "clsn/ui/Graphics.h"
#include "clsn/ui/HBoxContainer.h"

#include "clsn/draw/Region.h"

namespace clsn::ui::renderers
{
    void HBoxContainerRenderer::paint(Graphics& graphics,
                                      const Region& region,
                                      const Control& baseControl) const
    {
        auto& container = static_cast<const HBoxContainer&>(baseControl);

        const auto count = container.getCount();
        if (count == 0)
        {
            graphics.setDrawColor(container.getBackgroundColor());
            graphics.drawFillRectangle(region);
            return;
        }

        const auto regionWidth = region.getWidth() / count;
        for (int i = 0; i < count; i++)
        {
            Region controlRegion{(i * regionWidth) + region.getX(),
                                 region.getY(),
                                 regionWidth,
                                 region.getHeight()};
            if (container[i].isInvalidated())
            {
                container[i].paint(graphics, controlRegion);
                container[i].validate();
            }
        }
    }

}