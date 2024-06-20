#include "VBoxContainerRenderer.h"

#include "clsn/ui/VBoxContainer.h"

#include "clsn/draw/Region.h"

namespace clsn::ui::renderers
{
    void VBoxContainerRenderer::doLayout(Control& baseControl) const
    {
        auto& container = static_cast<VBoxContainer&>(baseControl);

        const auto visibleCount = container.getVisibleCount();
        if (visibleCount == 0)
            return;

        const auto width = container.getSize().getWidth();
        const auto height = container.getSize().getHeight() / static_cast<double>(visibleCount);

        const auto location = container.getLocation();

        const auto count = container.getCount();
        for (int i = 0, visibleSlot = 0; i < count; i++)
        {
            auto& control = container[i];
            if (!control.isVisible())
                continue;

            control.setLocation({location.getX(), static_cast<int>(visibleSlot * height) + location.getY()});
            control.setSize({width, static_cast<int>(height)});
            visibleSlot++;
        }
    }
}