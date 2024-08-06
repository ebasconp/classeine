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

        const auto width = getActualSize().getWidth();
        [[maybe_unused]] const auto height = getActualSize().getHeight();

        const auto position = getActualPosition();
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

                control.setActualPosition({currentx, currenty});
                control.setActualSize(preferredSize);
            }
            else
            {
                currentx = 0;
                currenty += maxy;

                const auto& preferredSize = control.getActualPreferredSize();
                if (maxy < preferredSize.getHeight())
                    maxy = preferredSize.getHeight();

                control.setActualPosition({currentx, currenty});
                control.setActualSize(preferredSize);
            }

            currentx += controlWidth;
        });
    }

}