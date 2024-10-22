// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/PaintableControl.h>
#include <clsn/ui/UIManager.h>

namespace clsn::ui
{
    CLSN_CPP_PROPERTY(PaintableControl, BackgroundColor, std::optional<draw::Color>)
    CLSN_CPP_PROPERTY(PaintableControl, Font, std::optional<clsn::draw::Font>)
    CLSN_CPP_PROPERTY(PaintableControl, ForegroundColor, std::optional<clsn::draw::Color>)

    PaintableControl::PaintableControl(std::string_view sectionName)
    : Control{sectionName}
    {}

    auto PaintableControl::getActualBackgroundColor() const -> const draw::Color&
    {
        const auto& Color = getBackgroundColor();
        if (Color.has_value())
            return Color.value();

        return UIManager::get_instance().getColor(
                    getDefaultSectionName(), "controlBackgroundColor");
    }

    auto PaintableControl::getActualForegroundColor() const -> const draw::Color&
    {
        const auto& Color = getForegroundColor();
        if (Color.has_value())
            return Color.value();

        return UIManager::get_instance().getColor(
                    getDefaultSectionName(), "controlForegroundColor");
    }

    auto PaintableControl::getActualFont() const -> const draw::Font&
    {
        const auto& Font = getFont();
        if (Font.has_value())
            return Font.value();

        return UIManager::get_instance().getFont(getDefaultSectionName(), "defaultRegularFont");
    }
}