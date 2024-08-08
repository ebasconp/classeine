#include "XYContainer.h"

namespace clsn::ui
{
    XYContainer::XYContainer()
    : ListContainer("XYContainer")
    {
    }

    void XYContainer::do_layout()
    {
        const auto visibleCount = get_visible_count();
        if (visibleCount == 0)
            return;

        const auto position = get_actual_position();

        iterate([&position](auto& control, auto& constraint)
        {
            if (!control.is_visible())
                return;

            control.set_actual_position({position.get_x() + constraint.get_x(), position.get_y() + constraint.get_y()});
            control.set_actual_size(control.get_actual_preferred_size());
        });
    }
}