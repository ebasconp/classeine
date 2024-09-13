// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "clsn/ui/ui_theme.h"

namespace clsn::ui::amatista
{
    class amatista_ui_theme : public ui_theme
    {
    public:
        amatista_ui_theme() = default;

        void populate_defaults() final;
        
    protected:
        virtual auto get_default_regular_font() const -> font;
        virtual auto get_default_bold_font() const -> font;
        virtual auto get_default_italic_font() const -> font;
        virtual auto get_default_bold_italic_font() const -> font;

        virtual auto get_button_preferred_size() const -> dimension;

        virtual auto get_bevel_up_color() const -> color = 0;
        virtual auto get_bevel_down_color() const -> color = 0;
        virtual auto get_container_background_color() const -> color = 0;
        virtual auto get_container_foreground_color() const -> color = 0;
        virtual auto get_control_background_color() const -> color = 0;
        virtual auto get_control_foreground_color() const -> color = 0;
        virtual auto get_control_hovered_background_color() const -> color = 0;
        virtual auto get_disabled_background_color() const -> color = 0;
        virtual auto get_disabled_foreground_color() const -> color = 0;

        virtual auto get_button_pressed_background_color() const -> color = 0;

    };
}