// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "DarkAmatistaUITheme.h"

#include "clsn/draw/Colors.h"

namespace clsn::ui::amatista
{
    using namespace clsn::draw;
    
    auto DarkAmatistaUITheme::getBevelUpColor() const -> Color
    {
        return Color{0, 92, 155 };
    }

    auto DarkAmatistaUITheme::getBevelDownColor() const -> Color
    {
        return Color{0, 49, 83 };
    }

    auto DarkAmatistaUITheme::getContainerBackgroundColor() const -> Color
    {
        return Color{0, 25, 42};
    }

    auto DarkAmatistaUITheme::getContainerForegroundColor() const -> Color
    {
        return Colors::makeWhite();
    }

    auto DarkAmatistaUITheme::getControlBackgroundColor() const -> Color
    {
        return Color{0, 49, 83};
    }

    auto DarkAmatistaUITheme::getControlForegroundColor() const -> Color
    {
        return Color{240, 240, 250};
    }

    auto DarkAmatistaUITheme::getControlHoveredBackgroundColor() const -> Color
    {
        return Color{0, 30, 60};
    }

    auto DarkAmatistaUITheme::getDisabledBackgroundColor() const -> Color
    {
        return Color{0x60, 0x60, 0x60};
    }

    auto DarkAmatistaUITheme::getDisabledForegroundColor() const -> Color
    {
        return Color{0, 25, 42};
    }

    auto DarkAmatistaUITheme::getButtonPressedBackgroundColor() const -> Color
    {
        return Color{0, 35, 60};
    }
}