// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/renderers/radio_button_renderer.h>

#include <clsn/ui/radio_button.h>
#include <clsn/ui/ui_manager.h>

#include <clsn/ui/layouts/dual_layout.h>

#include <clsn/ui/painters/background_painter.h>
#include <clsn/ui/painters/label_painter.h>
#include <clsn/ui/painters/radio_button_painter.h>

#include <clsn/draw/Colors.h>
#include <clsn/draw/Region.h>

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

    void radio_button_renderer::paint(graphics& gfx,
                   const Region& rgn,
                   const control& base_ctrl) const
    {
        const auto& rd_btn = static_cast<const radio_button&>(base_ctrl);

        const auto sectionName = rd_btn.get_default_section_name();

        const auto btn_clr = rd_btn.is_pressed()
            ? Color{192, 192, 192}
            : ui_manager::get_instance().getColor(sectionName, "control_background_color");

        using namespace clsn::ui::painters;
        using namespace clsn::ui::layouts;

        background_painter::paint_background(gfx, rgn, btn_clr);

        const auto text_size = gfx.get_text_size(rd_btn.get_actual_font(), rd_btn.getCaption());
        const auto size = text_size.getHeight();

        dual_layout layout;

        dual_layout::layout_element_info_vector infos;
        infos.emplace_back(draw::Region{0, 0, size, size}, dual_layout_constraint::use_preferred_size, true);
        infos.emplace_back(draw::Region{0, 0, 0, 0}, dual_layout_constraint::use_all_available_space, true);

        layout.do_layout(rgn, infos);

        radio_button_painter::paint_radio_button(gfx, infos[0].get_output_region(), rd_btn, size);

        using namespace clsn::ui::painters;
        painting_info info{TextHorizontalAlignment::left, TextVerticalAlignment::middle};

        label_painter::paint_label(gfx, infos[1].get_output_region(), rd_btn, info);
    }
}