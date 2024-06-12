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

        const auto controls = container.getVisibleControls();
        const auto visibleCount = container.getVisibleCount();
        if (visibleCount == 0)
        {
            graphics.setDrawColor(container.getBackgroundColor());
            graphics.drawFillRectangle(region);
            return;
        }

        const auto regionWidth = region.getWidth() / static_cast<double>(visibleCount);
        for (int i = 0; i < visibleCount; i++)
        {
            Region controlRegion{
                static_cast<int>((i * regionWidth) + region.getX()),
                region.getY(),
                static_cast<int>(regionWidth),
                region.getHeight()};

            auto& control = *(controls[i]);
            if (control.isInvalidated())
            {
                control.paint(graphics, controlRegion);
                control.validate();
            }
        }
    }

}