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

        const auto width = get_actual_size().getWidth() /
                           static_cast<double>(visibleCount);
        const auto height = get_actual_size().getHeight();

        const auto position = get_actual_position();

        const auto count = getCount();
        for (int i = 0, visibleSlot = 0; i < count; i++)
        {
            auto& control = (*this)[i];
            if (!control.is_visible())
                continue;

            control.set_actual_position(
                {static_cast<int>((visibleSlot * width) + position.getX()),
                 position.getY()});
            control.set_actual_size({static_cast<int>(width), height});
            visibleSlot++;
        }
    }
}