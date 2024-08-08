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

        const auto width = get_actual_size().getWidth();
        const auto height = get_actual_size().getHeight() /
                            static_cast<double>(visibleCount);

        const auto position = get_actual_position();

        const auto count = getCount();
        for (int i = 0, visibleSlot = 0; i < count; i++)
        {
            auto& control = (*this)[i];
            if (!control.is_visible())
                continue;

            control.set_actual_position(
                {position.getX(),
                 static_cast<int>(visibleSlot * height) + position.getY()});
            control.set_actual_size({width, static_cast<int>(height)});
            visibleSlot++;
        }
    }

}