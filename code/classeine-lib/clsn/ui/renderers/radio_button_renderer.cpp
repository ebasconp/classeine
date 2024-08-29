#include "radio_button_renderer.h"

#include "clsn/ui/radio_button.h"
#include "clsn/ui/ui_manager.h"

#include "clsn/ui/layouts/dual_layout.h"

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
        using namespace clsn::ui::layouts;

        background_painter::paint_background(gfx, rgn, btn_clr);

        const auto text_size = gfx.get_text_size(rd_btn.get_actual_font(), rd_btn.get_text());
        const auto size = text_size.get_height();

        dual_layout layout;
        layout.add({0, 0, size, size}, dual_layout_constraint::use_preferred_size);
        layout.add({0, 0, 0, 0}, dual_layout_constraint::use_all_available_space);

        layout.layout(rgn);

        radio_button_painter::paint_radio_button(gfx, layout.get_element_at(0).m_region, rd_btn, size);

        using namespace clsn::ui::painters::label_painter;
        painting_info info{text_horizontal_alignment::left, text_vertical_alignment::middle};

        label_painter::paint_label(gfx, layout.get_element_at(1).m_region, base_ctrl, info);
    }
}