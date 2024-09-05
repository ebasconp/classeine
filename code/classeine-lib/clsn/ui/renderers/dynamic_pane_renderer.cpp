#include "dynamic_pane_renderer.h"

#include "clsn/ui/dynamic_pane.h"

namespace clsn::ui::renderers
{
    void dynamic_pane_renderer::paint(graphics& gfx,
                              const region& rgn,
                              const control& ctrl) const
    {
        const auto& dyn_pane = static_cast<const dynamic_pane&>(ctrl);

        const auto& inner_ctrl = dyn_pane.get_inner_control();
        if (inner_ctrl == nullptr)
            return;

        inner_ctrl->paint(gfx, rgn);
    }
}
