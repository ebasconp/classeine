#include "VBoxContainerRenderer.h"

namespace clsn::ui::renderers
{
    void VBoxContainerRenderer::doLayout(Control& baseControl) const
    {
        auto& container = static_cast<VBoxContainer&>(baseControl);

        const auto visibleCount = container.getVisibleCount();
        if (visibleCount == 0)
            return;

        const auto width = container.getActualSize().getWidth();
        const auto height = container.getActualSize().getHeight() /
                            static_cast<double>(visibleCount);

        const auto position = container.getActualPosition();

        const auto count = container.getCount();
        for (int i = 0, visibleSlot = 0; i < count; i++)
        {
            auto& control = container[i];
            if (!control.isVisible())
                continue;

            control.setActualPosition(
                {position.getX(),
                 static_cast<int>(visibleSlot * height) + position.getY()});
            control.setActualSize({width, static_cast<int>(height)});
            visibleSlot++;
        }
    }
}