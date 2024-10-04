// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/control.h>

namespace clsn::ui
{
    /// This class exposes properties for handling background and foreground
    /// colors, as well as fonts.
    class paintable_control : public clsn::ui::control
    {
    public:
        explicit paintable_control(std::string_view name);

        CLSN_PROPERTY(background_color, std::optional<draw::color>, true);
        CLSN_PROPERTY(font, std::optional<clsn::draw::font>, true);
        CLSN_PROPERTY(foreground_color, std::optional<clsn::draw::color>, true);

        auto get_actual_background_color() const -> const clsn::draw::color&;
        auto get_actual_foreground_color() const -> const clsn::draw::color&;
        auto get_actual_font() const -> const clsn::draw::font&;

    };
}
