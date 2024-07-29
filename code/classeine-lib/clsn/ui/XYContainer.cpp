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

        const auto position = getActualPosition();

        iterate([&position](auto& control, auto& constraint)
        {
            if (!control.isVisible())
                return;

            control.setActualPosition({position.getX() + constraint.getX(), position.getY() + constraint.getY()});
            control.setActualSize(control.getActualPreferredSize());
        });
    }
}