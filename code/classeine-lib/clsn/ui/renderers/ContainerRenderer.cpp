#include "ContainerRenderer.h"

#include "clsn/ui/Graphics.h"
#include "clsn/ui/ListContainer.h"

#include "clsn/draw/Region.h"

namespace clsn::ui::renderers
{
    void ContainerRenderer::paint(Graphics& graphics,
                                      const Region& region,
                                      const Control& baseControl) const
    {
        auto& container = static_cast<const ListContainer<Empty>&>(baseControl);

        const auto visibleCount = container.getVisibleCount();
        if (visibleCount == 0)
        {
            graphics.setDrawColor(container.getBackgroundColor());
            graphics.drawFillRectangle(region);
            return;
        }

        const auto count = container.getCount();
        for (int i = 0; i < count; i++)
        {
            auto& control = container[i];
            if (!control.isVisible() || !control.isInvalidated())
                continue;

            Region controlRegion{control.getLocation(), control.getSize()};

            control.paint(graphics, controlRegion);
            control.validate();
        }
    }
}