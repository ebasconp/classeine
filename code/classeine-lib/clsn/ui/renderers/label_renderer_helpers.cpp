#include "label_renderer_helpers.h"

#include "clsn/draw/color.h"
#include "clsn/draw/region.h"

#include "clsn/ui/control.h"
#include "clsn/ui/ui_manager.h"


namespace clsn::ui::renderers::label_renderer_helpers
{
    using namespace clsn::draw;

    void draw_control_text(graphics& graphics, const control& control, const region& reg)
    {
        if (!control.is_enabled())
        {
            graphics.set_draw_color({192, 192, 192});
            graphics.draw_text(reg + region{1, 1, 0, 0},
                              control.get_actual_font(),
                              control.get_text());
        }

        graphics.set_draw_color(control.is_enabled()
                              ? control.get_actual_foreground_color()
                              : ui_manager::get_instance().get_color(
                                    "Theme", "disabledForegroundColor")
                          );

        graphics.draw_text(reg,
                          control.get_actual_font(),
                          control.get_text());
    }
}