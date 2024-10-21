// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/control.h>

namespace clsn::ui
{
    /// This class exposes properties for handling background and foreground
    /// Colors, as well as fonts.
    class paintable_control : public clsn::ui::control
    {
    public:
        explicit paintable_control(std::string_view name);

        CLSN_HEADER_PROPERTY(BackgroundColor, std::optional<draw::Color>, true)
        CLSN_HEADER_PROPERTY(Font, std::optional<clsn::draw::Font>, true)
        CLSN_HEADER_PROPERTY(ForegroundColor, std::optional<clsn::draw::Color>, true)

        auto get_actual_background_color() const -> const clsn::draw::Color&;
        auto get_actual_foreground_color() const -> const clsn::draw::Color&;
        auto get_actual_font() const -> const clsn::draw::Font&;

    };
}
