#include "dynamic_pane_renderer.h"

#include "clsn/ui/dynamic_pane.h"

#include "clsn/ui/painters/background_painter.h"

#include <clsn/ui/ui_manager.h>

namespace clsn::ui::renderers
{
    void dynamic_pane_renderer::paint(graphics& gfx,
                              const region& rgn,
                              const control& ctrl) const
    {
        const auto& dyn_pane = static_cast<const dynamic_pane&>(ctrl);

        const auto& inner_ctrl = dyn_pane.get_inner_control();
        if (inner_ctrl == nullptr)
        {
            const auto& clr = ui_manager::get_instance().get_color("", "container_background_color");
            painters::background_painter::paint_background(gfx, rgn, clr);
            return;
        }

        inner_ctrl->paint(gfx, rgn);
    }
}
