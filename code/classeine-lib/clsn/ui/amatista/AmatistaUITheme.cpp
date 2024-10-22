// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "AmatistaUITheme.h"

namespace clsn::ui::amatista
{
    using namespace clsn::draw;

    void AmatistaUITheme::populateDefaults()
    {
        add("", "bevelUpColor", getBevelUpColor());
        add("", "bevelDownColor", getBevelDownColor());
        add("", "containerBackgroundColor", getContainerBackgroundColor());
        add("", "containerForegroundColor", getContainerForegroundColor());
        add("", "controlBackgroundColor", getControlBackgroundColor());
        add("", "controlForegroundColor", getControlForegroundColor());
        add("", "controlHoveredBackgroundColor", getControlHoveredBackgroundColor());
        add("", "disabledBackgroundColor", getDisabledBackgroundColor());
        add("", "disabledForegroundColor", getDisabledForegroundColor());

        add("", "defaultRegularFont", getDefaultRegularFont());
        add("", "defaultBoldFont", getDefaultBoldFont());
        add("", "defaultItalicFont", getDefaultItalicFont());
        add("", "defaultBoldItalicFont", getDefaultBoldItalicFont());


        add("Button", "pressedBackgroundColor", getButtonPressedBackgroundColor());
        add("Button", "preferredSize", getButtonPreferredSize());
    }

    auto AmatistaUITheme::getDefaultRegularFont() const -> Font
    {
        return Font{"default", FontStyle::regular, 14};
    }

    auto AmatistaUITheme::getDefaultBoldFont() const -> Font
    {
        return Font{"bold", FontStyle::bold, 14};
    }

    auto AmatistaUITheme::getDefaultItalicFont() const -> Font
    {
        return Font{"italic", FontStyle::italic, 14};
    }

    auto AmatistaUITheme::getDefaultBoldItalicFont() const -> Font
    {
        return Font{"bold_italic", FontStyle::bold_italic, 14};
    }

    auto AmatistaUITheme::getButtonPreferredSize() const -> Dimension
    {
        return Dimension{96, 32};
    }
}