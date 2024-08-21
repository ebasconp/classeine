#include "label_renderer.h"

#include "clsn/ui/control.h"
#include "clsn/ui/ui_manager.h"

#include "clsn/ui/painters/label_painter.h"

namespace clsn::ui::renderers
{
    void label_renderer::paint(graphics& graphics,
                              const region& region,
                              const control& control) const
    {
        if (!control.is_invalidated())
            return;

        auto section_name = control.get_default_section_name();

        auto bc = ui_manager::get_instance().get_color(section_name, "container_background_color");

        graphics.set_draw_color(bc);
        graphics.draw_fill_rectangle(region);

        painters::label_painter::paint_label(graphics, region, control);
    }
}
