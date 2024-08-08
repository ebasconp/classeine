#include "FlowContainer.h"

namespace clsn::ui
{
    FlowContainer::FlowContainer()
    : ListContainer("FlowContainer")
    {
    }

    void FlowContainer::doLayout()
    {
        const auto visibleCount = getVisibleCount();
        if (visibleCount == 0)
            return;

        const auto width = get_actual_size().get_width();
        [[maybe_unused]] const auto height = get_actual_size().get_height();

        const auto position = get_actual_position();
        int currentx = position.get_x();
        int currenty = position.get_y();

        int maxx = currentx + width;
        int maxy = 0;

        iterate([&](auto& control, auto& )
        {
            auto controlWidth = control.getActualPreferredSize().get_width();
            [[maybe_unused]] auto controlHeight = control.getActualPreferredSize().get_height();

            if (currentx + controlWidth < maxx)
            {
                const auto& preferredSize = control.getActualPreferredSize();
                if (maxy < preferredSize.get_height())
                    maxy = preferredSize.get_height();

                control.set_actual_position({currentx, currenty});
                control.set_actual_size(preferredSize);
            }
            else
            {
                currentx = 0;
                currenty += maxy;

                const auto& preferredSize = control.getActualPreferredSize();
                if (maxy < preferredSize.get_height())
                    maxy = preferredSize.get_height();

                control.set_actual_position({currentx, currenty});
                control.set_actual_size(preferredSize);
            }

            currentx += controlWidth;
        });
    }

}