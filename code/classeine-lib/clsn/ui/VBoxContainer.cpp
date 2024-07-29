#include "VBoxContainer.h"

namespace clsn::ui
{
    VBoxContainer::VBoxContainer()
    : ListContainer("VBoxContainer")
    {
    }

    void VBoxContainer::doLayout()
    {
        const auto visibleCount = getVisibleCount();
        if (visibleCount == 0)
            return;

        const auto width = getActualSize().getWidth();
        const auto height = getActualSize().getHeight() /
                            static_cast<double>(visibleCount);

        const auto position = getActualPosition();

        const auto count = getCount();
        for (int i = 0, visibleSlot = 0; i < count; i++)
        {
            auto& control = (*this)[i];
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