#include "hbox_container.h"

namespace clsn::ui
{
    hbox_container::hbox_container()
    : list_container("hbox_container")
    {
    }

    void hbox_container::do_layout()
    {
        const auto visible_count = get_visible_count();
        if (visible_count == 0)
            return;

        const auto& actual_size = get_actual_size();
        const auto width = actual_size.get_width() / visible_count;
        const auto height = actual_size.get_height();

        const auto position = get_actual_position();

        const auto count = get_count();

        int last_x = 0;
        for (int i = 0; i < count; i++)
        {
            auto& control = (*this)[i];
            if (!control.is_visible())
                continue;

            auto actual_width = i < count - 1 ? width : actual_size.get_width() - last_x;
            control.set_actual_position({last_x + position.get_x(), position.get_y()});
            control.set_actual_size({actual_width, height});
            control.do_layout();

            last_x += width;
        }
    }
}