// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/paintable_control.h>
#include <clsn/ui/ui_manager.h>

namespace clsn::ui
{
    CLSN_CPP_PROPERTY(paintable_control, BackgroundColor, std::optional<draw::color>)
    CLSN_CPP_PROPERTY(paintable_control, Font, std::optional<clsn::draw::font>)
    CLSN_CPP_PROPERTY(paintable_control, ForegroundColor, std::optional<clsn::draw::color>)

    paintable_control::paintable_control(std::string_view sectionName)
    : control{sectionName}
    {}

    auto paintable_control::get_actual_background_color() const -> const draw::color&
    {
        const auto& color = getBackgroundColor();
        if (color.has_value())
            return color.value();

        return ui_manager::get_instance().get_color(
                    get_default_section_name(), "control_background_color");
    }

    auto paintable_control::get_actual_foreground_color() const -> const draw::color&
    {
        const auto& color = getForegroundColor();
        if (color.has_value())
            return color.value();

        return ui_manager::get_instance().get_color(
                    get_default_section_name(), "controlForegroundColor");
    }

    auto paintable_control::get_actual_font() const -> const draw::font&
    {
        const auto& font = getFont();
        if (font.has_value())
            return font.value();

        return ui_manager::get_instance().getFont(get_default_section_name(), "default_regular_font");
    }
}