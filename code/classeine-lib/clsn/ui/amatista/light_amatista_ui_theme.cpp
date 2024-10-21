// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "light_amatista_ui_theme.h"

#include "clsn/draw/Colors.h"

namespace clsn::ui::amatista
{
    using namespace clsn::draw;

    auto light_amatista_ui_theme::get_bevel_up_color() const -> Color
    {
        return Color{0, 92, 155 };
    }

    auto light_amatista_ui_theme::get_bevel_down_color() const -> Color
    {
        return Color{0, 49, 83 };
    }

    auto light_amatista_ui_theme::get_container_background_color() const -> Color
    {
        return Colors::makeWhite();
    }

    auto light_amatista_ui_theme::get_container_foreground_color() const -> Color
    {
        return Colors::makeBlack();
    }

    auto light_amatista_ui_theme::get_control_background_color() const -> Color
    {
        return Color{0xE0, 0xE0, 0xE0};
    }

    auto light_amatista_ui_theme::get_control_foreground_color() const -> Color
    {
        return Color{0, 49, 83};
    }

    auto light_amatista_ui_theme::get_control_hovered_background_color() const -> Color
    {
        return Color{0xF0, 0xF0, 0xF0};
    }

    auto light_amatista_ui_theme::get_disabled_background_color() const -> Color
    {
        return Color{0x60, 0x60, 0x60};
    }

    auto light_amatista_ui_theme::get_disabled_foreground_color() const -> Color
    {
        ;return Color{160, 160, 160};
    }

    auto light_amatista_ui_theme::get_button_pressed_background_color() const -> Color
    {
        return Color{192, 192, 192};
    }

}