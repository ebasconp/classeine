#include "LabelRendererHelpers.h"

#include "clsn/draw/color.h"
#include "clsn/draw/region.h"

#include "clsn/ui/control.h"
#include "clsn/ui/ui_manager.h"


namespace clsn::ui::renderers::LabelRendererHelpers
{
    using namespace clsn::draw;

    void drawControlText(graphics& graphics, const control& control, const region& region)
    {
        if (!control.is_enabled())
        {
            graphics.set_draw_color({192, 192, 192});
            graphics.draw_text(region + point{1, 1},
                              control.get_actual_font(),
                              control.get_text());
        }

        graphics.set_draw_color(control.is_enabled()
                              ? control.get_actual_foreground_color()
                              : ui_manager::get_instance().get_color(
                                    "Theme", "disabledForegroundColor")
                          );

        graphics.draw_text(region,
                          control.get_actual_font(),
                          control.get_text());
    }
}