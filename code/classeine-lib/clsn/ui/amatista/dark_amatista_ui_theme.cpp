// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/amatista/dark_amatista_ui_theme.h>

#include <clsn/draw/colors.h>

namespace clsn::ui::amatista
{
    using namespace clsn::draw;
    
    auto dark_amatista_ui_theme::get_bevel_up_color() const -> color
    {
        return color{0, 92, 155 };
    }

    auto dark_amatista_ui_theme::get_bevel_down_color() const -> color
    {
        return color{0, 49, 83 };
    }

    auto dark_amatista_ui_theme::get_container_background_color() const -> color
    {
        return color{0, 25, 42};
    }

    auto dark_amatista_ui_theme::get_container_foreground_color() const -> color
    {
        return colors::make_white();
    }

    auto dark_amatista_ui_theme::get_control_background_color() const -> color
    {
        return color{0, 49, 83};
    }

    auto dark_amatista_ui_theme::get_control_foreground_color() const -> color
    {
        return color{240, 240, 250};
    }

    auto dark_amatista_ui_theme::get_control_hovered_background_color() const -> color
    {
        return color{0, 30, 60};
    }

    auto dark_amatista_ui_theme::get_disabled_background_color() const -> color
    {
        return color{0x60, 0x60, 0x60};
    }

    auto dark_amatista_ui_theme::get_disabled_foreground_color() const -> color
    {
        return color{0, 25, 42};
    }

    auto dark_amatista_ui_theme::get_button_pressed_background_color() const -> color
    {
        return color{0, 35, 60};
    }
}