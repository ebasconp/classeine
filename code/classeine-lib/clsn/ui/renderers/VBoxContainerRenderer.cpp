#include "VBoxContainerRenderer.h"

#include "clsn/ui/Graphics.h"
#include "clsn/ui/VBoxContainer.h"

#include "clsn/draw/Region.h"

namespace clsn::ui::renderers
{
    void VBoxContainerRenderer::paint(Graphics& graphics,
                                      const Region& region,
                                      const Control& baseControl) const
    {
        auto& container = static_cast<const VBoxContainer&>(baseControl);

        const auto visibleCount = container.getVisibleCount();
        if (visibleCount == 0)
        {
            graphics.setDrawColor(container.getBackgroundColor());
            graphics.drawFillRectangle(region);
            return;
        }

        const auto regionHeight =
            region.getHeight() / static_cast<double>(visibleCount);

        const auto count = container.getCount();
        for (int i = 0; i < count; i++)
        {
            if (!container[i].isVisible())
                continue;

            Region controlRegion{region.getX(),
                                 static_cast<int>(i * regionHeight) + region.getY(),
                                 region.getWidth(),
                                 static_cast<int>(regionHeight)};

            if (container[i].isInvalidated())
            {
                container[i].paint(graphics, controlRegion);
                container[i].validate();
            }
        }
    }
}