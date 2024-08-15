#include "flow_container.h"

#include "renderers/flow_container_renderer.h"


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

        iterate_controls([&](control& ctrl)
        {
            auto controlWidth = ctrl.get_actual_preferred_size().get_width();

            if (currentx + controlWidth < maxx)
            {
                const auto& preferredSize = ctrl.get_actual_preferred_size();
                if (maxy < preferredSize.get_height())
                    maxy = preferredSize.get_height();

                ctrl.set_actual_position({currentx, currenty});
                ctrl.set_actual_size(preferredSize);
            }
            else
            {
                currentx = 0;
                currenty += maxy;

                const auto& preferredSize = ctrl.get_actual_preferred_size();
                if (maxy < preferredSize.get_height())
                    maxy = preferredSize.get_height();

                ctrl.set_actual_position({currentx, currenty});
                ctrl.set_actual_size(preferredSize);
            }

            ctrl.do_layout();
            currentx += controlWidth;
        });
    }

    auto flow_container::make_default_renderer() const -> std::unique_ptr<renderer_base>
    {
        return std::make_unique<renderers::flow_container_renderer>();
    }

}