#include "HBoxContainerRenderer.h"

#include "clsn/ui/HBoxContainer.h"

#include "clsn/draw/Region.h"

namespace clsn::ui::renderers
{
    void HBoxContainerRenderer::doLayout(Control& baseControl) const
    {
        auto& container = static_cast<HBoxContainer&>(baseControl);

        const auto visibleCount = container.getVisibleCount();
        if (visibleCount == 0)
            return;

        const auto width = container.getSize().getWidth() / static_cast<double>(visibleCount);
        const auto height = container.getSize().getHeight();

        const auto location = container.getLocation();

        const auto count = container.getCount();
        for (int i = 0, visibleSlot = 0; i < count; i++)
        {
            auto& control = container[i];
            if (!control.isVisible())
                continue;

            control.setLocation({static_cast<int>((visibleSlot * width) + location.getX()), location.getY()});
            control.setSize({static_cast<int>(width), height});
            visibleSlot++;
        }
    }
}