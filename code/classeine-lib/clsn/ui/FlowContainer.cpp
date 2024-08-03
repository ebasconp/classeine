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
        [[maybe_unused]] int currenty = position.getY();

        int maxx = currentx + width;

        iterate([&](auto& control, auto& )
        {
            auto controlWidth = control.getActualPreferredSize().getWidth();
            [[maybe_unused]] auto controlHeight = control.getActualPreferredSize().getHeight();

            if (currentx + controlWidth < maxx)
            {
                control.setActualPosition({currentx, currenty});
                control.setActualSize(control.getActualPreferredSize());
            }

            currentx += controlWidth;
        });
    }

}