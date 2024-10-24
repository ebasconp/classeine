// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/_private/tab_control_view_header_button.h>
#include <clsn/ui/_private/tab_control_view_header_button_renderer.h>

#include <clsn/ui/graphics.h>

#include <clsn/draw/point.h>
#include <clsn/draw/region.h>

namespace clsn::ui::_private
{
    void tab_control_view_header_button_renderer::paint(
                    graphics& gfx,
                    const clsn::draw::region& rgn,
                    const control& ctrl) const
    {
        toggle_button_renderer::paint(gfx, rgn, ctrl);

        gfx.set_draw_color(clsn::draw::color{255, 192, 0});

        auto& btn = static_cast<const tab_control_view_header_button&>(ctrl);
        if (btn.is_hovered() || !btn.is_checked())
            return;

        const auto bottom_left = clsn::draw::point{rgn.get_x() + 2, rgn.get_y() + rgn.get_height() - 1};
        const auto bottom_right = clsn::draw::point{rgn.get_x() + rgn.get_width() - 3, rgn.get_y() + rgn.get_height() - 1};

        gfx.draw_line(bottom_left, bottom_right);
        gfx.draw_line(bottom_left + clsn::draw::point{0, -1},
                      bottom_right + clsn::draw::point{0, -1});

        gfx.draw_line(bottom_left + clsn::draw::point{0, -2},
                      bottom_right + clsn::draw::point{0, -2});
    }
}
