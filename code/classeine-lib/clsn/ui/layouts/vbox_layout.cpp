#include "vbox_layout.h"

namespace clsn::ui::layouts
{
    void vbox_layout::layout(const region& rgn)
    {
        const auto visible_count = get_count();
        if (visible_count == 0)
             return;

        const auto& actual_size = rgn.get_size();
        const auto width = actual_size.get_width();
        const auto height = actual_size.get_height() / visible_count;

        const auto position = rgn.get_position();

        const auto count = get_count();
        int last_y = 0;
        for (int i = 0; i < count; i++)
        {
            auto& r = this->get_element_at(i).m_region;

            const auto actual_height = i < count - 1 ? height : actual_size.get_height() - last_y;

            r = { {position.get_x(), last_y + position.get_y()}, {width, actual_height} };

            last_y += height;
        }
    };
}