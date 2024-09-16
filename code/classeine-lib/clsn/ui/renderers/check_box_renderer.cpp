// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "check_box_renderer.h"

#include "clsn/ui/check_box.h"
#include "clsn/ui/ui_manager.h"

#include "clsn/ui/layouts/dual_layout.h"

#include "clsn/ui/painters/background_painter.h"
#include "clsn/ui/painters/check_box_painter.h"
#include "clsn/ui/painters/label_painter.h"

#include "clsn/draw/region.h"

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

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

        const auto text_size = gfx.get_text_size(chk_box.get_actual_font(), chk_box.get_text());

        const auto size = text_size.get_height();

        using namespace clsn::ui::layouts;
        dual_layout layout;
        layout.add({0, 0, size, size}, dual_layout_constraint::use_preferred_size);
        layout.add({0, 0, 0, 0}, dual_layout_constraint::use_all_available_space);

        layout.layout(rgn);

        check_box_painter::paint_check_box(gfx, layout.get_element_at(0).m_region, chk_box, size);

        using namespace clsn::ui::painters::label_painter;
        painting_info info{text_horizontal_alignment::left, text_vertical_alignment::middle};

        label_painter::paint_label(gfx, layout.get_element_at(1).m_region, chk_box, info);
    }
}