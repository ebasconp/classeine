#include "radio_button_renderer.h"

#include "clsn/ui/radio_button.h"
#include "clsn/ui/ui_manager.h"

#include "clsn/ui/painters/background_painter.h"
#include "clsn/ui/painters/label_painter.h"
#include "clsn/ui/painters/radio_button_painter.h"

#include "clsn/draw/colors.h"
#include "clsn/draw/region.h"


namespace clsn::ui::renderers
{
    void radio_button_renderer::paint(graphics& gfx,
                   const region& rgn,
                   const control& base_ctrl) const
    {
        const auto& rd_btn = static_cast<const radio_button&>(base_ctrl);

        const auto section_name = rd_btn.get_default_section_name();

        const auto btn_clr = rd_btn.is_pressed()
            ? color{192, 192, 192}
            : ui_manager::get_instance().get_color(section_name, "control_background_color");

        using namespace clsn::ui::painters;

        background_painter::paint_background(gfx, rgn, btn_clr);

        label_painter::paint_label(gfx, rgn, base_ctrl);

        const auto text_size = gfx.get_text_size(rd_btn.get_actual_font(), rd_btn.get_text());

        const auto mid = rd_btn.get_actual_position().get_y() + (rgn.get_height() - text_size.get_height()) / 2;
        const auto size = text_size.get_height();

        const auto x = 8 + rd_btn.get_actual_position().get_x();
        const auto y = mid - 1;

        radio_button_painter::paint_radio_button(gfx, {x, y, size, size}, rd_btn);
    }
}