// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/paintable_control.h>
#include <clsn/ui/ui_manager.h>

namespace clsn::ui
{
    CLSN_CPP_PROPERTY(paintable_control, BackgroundColor, std::optional<draw::Color>)
    CLSN_CPP_PROPERTY(paintable_control, Font, std::optional<clsn::draw::Font>)
    CLSN_CPP_PROPERTY(paintable_control, ForegroundColor, std::optional<clsn::draw::Color>)

    paintable_control::paintable_control(std::string_view sectionName)
    : control{sectionName}
    {}

    auto paintable_control::get_actual_background_color() const -> const draw::Color&
    {
        const auto& Color = getBackgroundColor();
        if (Color.has_value())
            return Color.value();

        return ui_manager::get_instance().getColor(
                    get_default_section_name(), "control_background_color");
    }

    auto paintable_control::get_actual_foreground_color() const -> const draw::Color&
    {
        const auto& Color = getForegroundColor();
        if (Color.has_value())
            return Color.value();

        return ui_manager::get_instance().getColor(
                    get_default_section_name(), "controlForegroundColor");
    }

    auto paintable_control::get_actual_font() const -> const draw::Font&
    {
        const auto& Font = getFont();
        if (Font.has_value())
            return Font.value();

        return ui_manager::get_instance().getFont(get_default_section_name(), "default_regular_font");
    }
}