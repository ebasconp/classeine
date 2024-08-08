#include "button_renderer.h"

#include "clsn/ui/button.h"
#include "clsn/ui/graphics.h"
#include "clsn/ui/ui_manager.h"

#include "clsn/draw/region.h"

#include "border_renderer_helpers.h"
#include "label_renderer_helpers.h"

#include <clsn/ui/window.h>

namespace
{
    using namespace clsn::ui;

    color getUltimateBackgroundColor(const button& button, bool is_hovered)
    {
        if (is_hovered)
        {
            return ui_manager::get_instance().get_color(button.get_default_section_name(), "controlHoveredBackgroundColor");
        }

        return button.get_actual_background_color();
    }
}

namespace clsn::ui::renderers
{
    using namespace clsn::draw;
    using namespace clsn::ui;

    auto button_renderer::paint_as_pressed(const clickable_control& button) const -> bool
    {
        return button.is_pressed();
    }

    void button_renderer::paint(graphics& graphics,
               const region& a_region,
               const control& baseControl) const
    {
        if (!baseControl.is_invalidated())
            return;

        auto& control = static_cast<const clsn::ui::button&>(baseControl);

        const auto section_name = control.get_default_section_name();
        const auto is_hovered = control.is_hovered();

        auto& unhoveredColor =
            ui_manager::get_instance().get_color(
                control.get_default_section_name(), "controlBackgroundColor");

        auto& bevelUp = is_hovered ? ui_manager::get_instance().get_color(
            section_name, "bevelUpColor") : unhoveredColor;
        auto& bevelDown = is_hovered ? ui_manager::get_instance().get_color(
            section_name, "bevelDownColor") : unhoveredColor;

        constexpr int depth = 2;

        const bool pressed = paint_as_pressed(control);

        border_renderer_helpers::drawFlatBorder(
            graphics, a_region, bevelUp, bevelDown, depth, !pressed);

        constexpr int depth2 = depth * 2;

        const region innerRect{a_region.get_x() + depth,
                               a_region.get_y() + depth,
                               a_region.get_width() - depth2,
                               a_region.get_height() - depth2};

        const auto& buttonColor = pressed
            ? ui_manager::get_instance().get_color("button", "pressedBackgroundColor")
            : getUltimateBackgroundColor(control, is_hovered);

        graphics.set_draw_color(buttonColor);
        graphics.draw_fill_rectangle(innerRect);
        if (pressed)
        {
            const region innerRectShifted{innerRect.get_x() + depth,
                                          innerRect.get_y() + depth,
                                          innerRect.get_width() - depth,
                                          innerRect.get_height() - depth};
            label_renderer_helpers::draw_control_text(graphics, baseControl, innerRectShifted);
        }
        else
        {
            label_renderer_helpers::draw_control_text(graphics, baseControl, innerRect);
        }
    }
}