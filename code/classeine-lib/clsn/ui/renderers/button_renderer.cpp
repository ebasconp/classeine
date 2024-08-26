#include "button_renderer.h"

#include "clsn/ui/button.h"
#include "clsn/ui/graphics.h"
#include "clsn/ui/ui_manager.h"

#include "clsn/draw/region.h"

#include "clsn/ui/painters/background_painter.h"
#include "clsn/ui/painters/border_painter.h"
#include "clsn/ui/painters/label_painter.h"

#include <clsn/ui/window.h>

namespace
{
    using namespace clsn::ui;

    color get_ultimate_background_color(const button& btn, bool is_hovered)
    {
        if (is_hovered)
        {
            return ui_manager::get_instance()
                    .get_color(btn.get_default_section_name(), "controlHoveredBackgroundColor");
        }

        return btn.get_actual_background_color();
    }
}

namespace clsn::ui::renderers
{
    using namespace clsn::draw;
    using namespace clsn::ui;

    auto button_renderer::paint_as_pressed(const clickable_control& btn) const -> bool
    {
       return btn.is_pressed();
    }

    void button_renderer::paint(graphics& gfx,
               const region& rgn,
               const control& ctrl) const
    {
        using namespace clsn::ui::painters;

        if (!ctrl.is_invalidated())
            return;

        auto& btn = static_cast<const clsn::ui::button&>(ctrl);

        // Paint background
        const auto is_hovered = btn.is_hovered();
        const bool pressed = paint_as_pressed(btn);

        const auto& btn_clr = pressed
             ? ui_manager::get_instance().get_color("button", "pressedBackgroundColor")
             : get_ultimate_background_color(btn, is_hovered);

        background_painter::paint_background(gfx, rgn, btn_clr);

        // paint border
        const auto section_name = btn.get_default_section_name();

        auto& unhovered_clr =
             ui_manager::get_instance().get_color(
                btn.get_default_section_name(), "control_background_color");

        const auto& clr = is_hovered
                 ? ui_manager::get_instance().get_color(section_name, "bevelUpColor")
                 : unhovered_clr;

        constexpr int depth = 2;
        border_painter::paint_flat_border(gfx, rgn, clr, depth);

        constexpr int depth2 = depth * 2;

        const region inner_rect = rgn + region{depth, depth, -depth2, -depth2};

        if (pressed)
        {
            const region inner_rect_shifted = inner_rect + region{depth, depth, -depth, -depth};
            label_painter::paint_label(gfx, inner_rect_shifted, ctrl);
        }
        else
        {
            label_painter::paint_label(gfx, inner_rect, ctrl);
        }
    }
}