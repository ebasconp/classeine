#include "HBoxContainerRenderer.h"

namespace clsn::ui::renderers
{
    void HBoxContainerRenderer::doLayout(Control& baseControl) const
    {
        auto& container = static_cast<HBoxContainer&>(baseControl);

        const auto visibleCount = container.getVisibleCount();
        if (visibleCount == 0)
            return;

        const auto width = container.getActualSize().getWidth() /
                           static_cast<double>(visibleCount);
        const auto height = container.getActualSize().getHeight();

        const auto position = container.getActualPosition();

        const auto count = container.getCount();
        for (int i = 0, visibleSlot = 0; i < count; i++)
        {
            auto& control = container[i];
            if (!control.isVisible())
                continue;

            control.setActualPosition(
                {static_cast<int>((visibleSlot * width) + position.getX()),
                 position.getY()});
            control.setActualSize({static_cast<int>(width), height});
            visibleSlot++;
        }
    }
}