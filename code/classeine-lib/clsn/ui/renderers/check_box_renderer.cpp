#include "check_box_renderer.h"

#include "clsn/ui/check_box.h"
#include "clsn/ui/ui_manager.h"

#include "clsn/ui/painters/background_painter.h"
#include "clsn/ui/painters/check_box_painter.h"
#include "clsn/ui/painters/label_painter.h"

#include "clsn/draw/region.h"

namespace clsn::ui::renderers
{
    void check_box_renderer::paint(graphics& gfx,
                   const region& rgn,
                   const control& ctrl) const
    {
        const auto& chk_box = static_cast<const check_box&>(ctrl);
        const auto section_name = chk_box.get_default_section_name();

        const auto btn_clr = chk_box.is_pressed()
            ? color{192, 192, 192}
            : ui_manager::get_instance().get_color(section_name, "control_background_color");

        using namespace clsn::ui::painters;

        background_painter::paint_background(gfx, rgn, btn_clr);

        label_painter::paint_label(gfx, rgn, ctrl);

        const auto text_size = gfx.get_text_size(chk_box.get_actual_font(), chk_box.get_text());

        const auto mid = chk_box.get_actual_position().get_y() + (rgn.get_height() - text_size.get_height()) / 2;
        const auto size = text_size.get_height();

        const auto x = 8 + chk_box.get_actual_position().get_x();
        const auto y = mid - 1;

        check_box_painter::paint_check_box(gfx, {x, y, size, size}, chk_box);
    }
}