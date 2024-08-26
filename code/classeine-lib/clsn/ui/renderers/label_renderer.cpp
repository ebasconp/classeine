#include "label_renderer.h"

#include "clsn/ui/control.h"
#include "clsn/ui/ui_manager.h"

#include "clsn/ui/painters/background_painter.h"
#include "clsn/ui/painters/label_painter.h"

namespace clsn::ui::renderers
{
    void label_renderer::paint(graphics& gfx,
                              const region& rgn,
                              const control& ctrl) const
    {
        const auto section_name = ctrl.get_default_section_name();

        const auto bc = ui_manager::get_instance().get_color(section_name, "container_background_color");

        painters::background_painter::paint_background(gfx, rgn ,bc);

        painters::label_painter::paint_label(gfx, rgn, ctrl);
    }
}
