#include "vbox_container.h"

namespace clsn::ui
{
    vbox_container::vbox_container()
    : list_container("vbox_container")
    {
    }

    void vbox_container::do_layout()
    {
        const auto visible_count = get_visible_count();
        if (visible_count == 0)
            return;

        const auto& actual_size = get_actual_size();
        const auto width = actual_size.get_width();
        const auto height = actual_size.get_height() / visible_count;

        const auto position = get_actual_position();

        const auto count = get_count();
        int last_y = 0;
        for (int i = 0; i < count; i++)
        {
            auto& control = (*this)[i];
            if (!control.is_visible())
                continue;

            const auto actual_height = i < count - 1 ? height : actual_size.get_height() - last_y;
            control.set_actual_position({position.get_x(), last_y + position.get_y()});
            control.set_actual_size({width, actual_height});

            last_y += height;
        }
    }

}