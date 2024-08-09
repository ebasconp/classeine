#include "flow_container.h"

namespace clsn::ui
{
    flow_container::flow_container()
    : list_container("flow_container")
    {
    }

    void flow_container::do_layout()
    {
        const auto visibleCount = get_visible_count();
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
            auto controlWidth = control.get_actual_preferred_size().get_width();
            [[maybe_unused]] auto controlHeight = control.get_actual_preferred_size().get_height();

            if (currentx + controlWidth < maxx)
            {
                const auto& preferredSize = control.get_actual_preferred_size();
                if (maxy < preferredSize.get_height())
                    maxy = preferredSize.get_height();

                control.set_actual_position({currentx, currenty});
                control.set_actual_size(preferredSize);
            }
            else
            {
                currentx = 0;
                currenty += maxy;

                const auto& preferredSize = control.get_actual_preferred_size();
                if (maxy < preferredSize.get_height())
                    maxy = preferredSize.get_height();

                control.set_actual_position({currentx, currenty});
                control.set_actual_size(preferredSize);
            }

            control.do_layout();
            currentx += controlWidth;
        });
    }

}