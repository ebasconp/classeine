#include "HBoxContainer.h"

namespace clsn::ui
{
    HBoxContainer::HBoxContainer()
    : ListContainer("HBoxContainer")
    {
    }

    void HBoxContainer::doLayout()
    {
        const auto visibleCount = getVisibleCount();
        if (visibleCount == 0)
            return;

        const auto width = getActualSize().getWidth() /
                           static_cast<double>(visibleCount);
        const auto height = getActualSize().getHeight();

        const auto position = getActualPosition();

        const auto count = getCount();
        for (int i = 0, visibleSlot = 0; i < count; i++)
        {
            auto& control = (*this)[i];
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