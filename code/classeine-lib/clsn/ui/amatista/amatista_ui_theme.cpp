// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "amatista_ui_theme.h"

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

    auto amatista_ui_theme::get_default_regular_font() const -> Font
    {
        return Font{"default", FontStyle::regular, 14};
    }

    auto amatista_ui_theme::get_default_bold_font() const -> Font
    {
        return Font{"bold", FontStyle::bold, 14};
    }

    auto amatista_ui_theme::get_default_italic_font() const -> Font
    {
        return Font{"italic", FontStyle::italic, 14};
    }

    auto amatista_ui_theme::get_default_bold_italic_font() const -> Font
    {
        return Font{"bold_italic", FontStyle::bold_italic, 14};
    }

    auto amatista_ui_theme::get_button_preferred_size() const -> Dimension
    {
        return Dimension{96, 32};
    }
}