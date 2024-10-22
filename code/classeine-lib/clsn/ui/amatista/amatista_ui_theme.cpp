// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/amatista/amatista_ui_theme.h>

namespace clsn::ui::amatista
{
    using namespace clsn::draw;

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

        add("", "default_regular_font", get_default_regular_font());
        add("", "default_bold_font", get_default_bold_font());
        add("", "default_italic_font", get_default_italic_font());
        add("", "default_bold_italic_font", get_default_bold_italic_font());


        add("button", "pressedBackgroundColor", get_button_pressed_background_color());
        add("button", "preferredSize", get_button_preferred_size());
    }

    auto amatista_ui_theme::get_default_regular_font() const -> font
    {
        return font{"default", font_style::regular, 14};
    }

    auto amatista_ui_theme::get_default_bold_font() const -> font
    {
        return font{"bold", font_style::bold, 14};
    }

    auto amatista_ui_theme::get_default_italic_font() const -> font
    {
        return font{"italic", font_style::italic, 14};
    }

    auto amatista_ui_theme::get_default_bold_italic_font() const -> font
    {
        return font{"bold_italic", font_style::bold_italic, 14};
    }

    auto amatista_ui_theme::get_button_preferred_size() const -> dimension
    {
        return dimension{96, 32};
    }
}