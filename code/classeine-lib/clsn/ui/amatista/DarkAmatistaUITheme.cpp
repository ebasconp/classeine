#include "DarkAmatistaUITheme.h"

#include "clsn/draw/colors.h"

namespace clsn::ui::amatista
{
    auto DarkAmatistaUITheme::getBevelUpColor() const -> color
    {
        return color{0, 92, 155 };
    }

    auto DarkAmatistaUITheme::getBevelDownColor() const -> color
    {
        return color{0, 49, 83 };
    }

    auto DarkAmatistaUITheme::getContainerBackgroundColor() const -> color
    {
        return color{0, 25, 42};
    }

    auto DarkAmatistaUITheme::getContainerForegroundColor() const -> color
    {
        return colors::make_white();
    }

    auto DarkAmatistaUITheme::getControlBackgroundColor() const -> color
    {
        return color{0, 49, 83};
    }

    auto DarkAmatistaUITheme::getControlForegroundColor() const -> color
    {
        return color{240, 240, 250};
    }

    auto DarkAmatistaUITheme::getControlHoveredBackgroundColor() const -> color
    {
        return color{0, 30, 60};
    }

    auto DarkAmatistaUITheme::getDisabledBackgroundColor() const -> color
    {
        return color{0x60, 0x60, 0x60};
    }

    auto DarkAmatistaUITheme::getDisabledForegroundColor() const -> color
    {
        return color{0, 25, 42};
    }

    auto DarkAmatistaUITheme::getButtonPressedBackgroundColor() const -> color
    {
        return color{0, 35, 60};
    }
}