#include "amatista_ui_theme.h"

#include "clsn/draw/colors.h"

namespace clsn::ui::amatista
{
    void amatista_ui_theme::populate_defaults()
    {
        add("", "bevelUpColor", get_bevel_up_color());
        add("", "bevelDownColor", get_bevel_down_color());
        add("", "container_background_color", get_container_background_color());
        add("", "container_foreground_color", get_container_foreground_color());
        add("", "control_background_color", get_control_background_color());
        add("", "controlForegroundColor", get_control_foreground_color());
        add("", "controlHoveredBackgroundColor", get_control_hovered_background_color());
        add("", "disabledBackgroundColor", get_disabled_background_color());
        add("", "disabledForegroundColor", get_disabled_foreground_color());

        add("", "defaultFont", get_default_font());

        add("button", "pressedBackgroundColor", get_button_pressed_background_color());
        add("button", "preferredSize", get_button_preferred_size());
    }

    auto amatista_ui_theme::get_default_font() const -> font
    {
        return font{"Default", font_style::regular, 14};
    }

    auto amatista_ui_theme::get_button_preferred_size() const -> dimension
    {
        return dimension{96, 32};
    }
}