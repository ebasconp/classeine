#include "xy_container.h"

#include "renderers/xy_container_renderer.h"

namespace clsn::ui
{
    xy_container::xy_container()
    : list_container("xy_container")
    {
    }

    void xy_container::do_layout()
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
            control.do_layout();
        });
    }

    auto xy_container::make_default_renderer() const -> std::unique_ptr<renderer_base>
    {
        return std::make_unique<renderers::xy_container_renderer>();
    }
}