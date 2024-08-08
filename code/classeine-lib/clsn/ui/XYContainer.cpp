#include "XYContainer.h"

namespace clsn::ui
{
    XYContainer::XYContainer()
    : ListContainer("XYContainer")
    {
    }

    void XYContainer::doLayout()
    {
        const auto visibleCount = getVisibleCount();
        if (visibleCount == 0)
            return;

        const auto position = get_actual_position();

        iterate([&position](auto& control, auto& constraint)
        {
            if (!control.is_visible())
                return;

            control.set_actual_position({position.getX() + constraint.getX(), position.getY() + constraint.getY()});
            control.set_actual_size(control.getActualPreferredSize());
        });
    }
}