// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/renderers/label_renderer.h>

#include <clsn/ui/label.h>
#include <clsn/ui/ui_manager.h>

#include <clsn/ui/painters/background_painter.h>
#include <clsn/ui/painters/label_painter.h>

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

    void label_renderer::paint(graphics& gfx,
                              const region& rgn,
                              const control& ctrl) const
    {
        const auto sectionName = ctrl.get_default_section_name();

        const auto& _label = static_cast<const label&>(ctrl);

        const auto bc = _label.getBackgroundColor().has_value()
                ? _label.getBackgroundColor().value()
                : ui_manager::get_instance().get_color(sectionName, "container_background_color");

        painters::background_painter::paint_background(gfx, rgn, bc);

        using namespace clsn::ui::painters;
        painting_info info{_label.get_horizontal_alignment(),
                           _label.get_vertical_alignment()};

        label_painter::paint_label(gfx, rgn, _label, info);
    }
}
