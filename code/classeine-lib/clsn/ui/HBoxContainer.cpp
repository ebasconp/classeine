#include "HBoxContainer.h"

namespace clsn::ui
{
    HBoxContainer::HBoxContainer()
    : ListContainer("HBoxContainer")
    {
    }

    void HBoxContainer::do_layout()
    {
        const auto visibleCount = get_visible_count();
        if (visibleCount == 0)
            return;

        const auto width = get_actual_size().get_width() /
                           static_cast<double>(visibleCount);
        const auto height = get_actual_size().get_height();

        const auto position = get_actual_position();

        const auto count = getCount();
        for (int i = 0, visibleSlot = 0; i < count; i++)
        {
            auto& control = (*this)[i];
            if (!control.is_visible())
                continue;

            control.set_actual_position(
                {static_cast<int>((visibleSlot * width) + position.get_x()),
                 position.get_y()});
            control.set_actual_size({static_cast<int>(width), height});
            visibleSlot++;
        }
    }
}