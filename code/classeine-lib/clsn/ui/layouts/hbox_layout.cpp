#include "hbox_layout.h"

namespace clsn::ui::layouts
{
    void hbox_layout::layout(const region& rgn)
    {
        const auto count = get_count();

        const auto& actual_size = rgn.get_size();
        const auto width = actual_size.get_width() / count;
        const auto height = actual_size.get_height();

        const auto position = rgn.get_position();

        int last_x = 0;
        for (int i = 0; i < count; i++)
        {
            auto& r = get_element_at(i).m_region;

            auto actual_width = i < count - 1 ? width : actual_size.get_width() - last_x;

            r = { {last_x + position.get_x(), position.get_y()}, {actual_width, height} };

            last_x += width;
        }
    };
}