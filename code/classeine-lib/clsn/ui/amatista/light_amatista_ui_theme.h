// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "clsn/ui/amatista/amatista_ui_theme.h"

namespace clsn::ui::amatista
{
    class light_amatista_ui_theme final : public amatista_ui_theme
    {
    public:
        light_amatista_ui_theme() = default;

    protected:
        auto get_bevel_up_color() const -> draw::color override;
        auto get_bevel_down_color() const -> draw::color override;
        auto get_container_background_color() const -> draw::color override;
        auto get_container_foreground_color() const -> draw::color override;
        auto get_control_background_color() const -> draw::color override;
        auto get_control_foreground_color() const -> draw::color override;
        auto get_control_hovered_background_color() const -> draw::color override;
        auto get_disabled_background_color() const -> draw::color override;
        auto get_disabled_foreground_color() const -> draw::color override;

        auto get_button_pressed_background_color() const -> draw::color override;
    };
}