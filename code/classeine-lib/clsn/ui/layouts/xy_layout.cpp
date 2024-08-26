#include "xy_layout.h"

namespace clsn::ui::layouts
{
    void xy_layout::layout(const region& rgn)
    {
        const auto count = get_count();
        if (count == 0)
            return;

        const auto& position = rgn.get_position();

        for (int i = 0; i < count; i++)
        {
            auto& elem = get_element_at(i);

            elem.m_region = { {position.get_x() + elem.m_constraint.get_x(), position.get_y() + elem.m_constraint.get_y()},
                                elem.m_region.get_size() };
        }
    };
}