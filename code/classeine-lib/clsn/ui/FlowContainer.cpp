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

        const auto width = get_actual_size().getWidth();
        [[maybe_unused]] const auto height = get_actual_size().getHeight();

        const auto position = get_actual_position();
        int currentx = position.getX();
        int currenty = position.getY();

        int maxx = currentx + width;
        int maxy = 0;

        iterate([&](auto& control, auto& )
        {
            auto controlWidth = control.getActualPreferredSize().getWidth();
            [[maybe_unused]] auto controlHeight = control.getActualPreferredSize().getHeight();

            if (currentx + controlWidth < maxx)
            {
                const auto& preferredSize = control.getActualPreferredSize();
                if (maxy < preferredSize.getHeight())
                    maxy = preferredSize.getHeight();

                control.set_actual_position({currentx, currenty});
                control.set_actual_size(preferredSize);
            }
            else
            {
                currentx = 0;
                currenty += maxy;

                const auto& preferredSize = control.getActualPreferredSize();
                if (maxy < preferredSize.getHeight())
                    maxy = preferredSize.getHeight();

                control.set_actual_position({currentx, currenty});
                control.set_actual_size(preferredSize);
            }

            currentx += controlWidth;
        });
    }

}