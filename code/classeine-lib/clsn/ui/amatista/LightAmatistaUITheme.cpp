#include "LightAmatistaUITheme.h"

#include "clsn/draw/colors.h"

namespace clsn::ui::amatista
{
    auto LightAmatistaUITheme::getBevelUpColor() const -> color
    {
        return color{0, 92, 155 };
    }

    auto LightAmatistaUITheme::getBevelDownColor() const -> color
    {
        return color{0, 49, 83 };
    }

    auto LightAmatistaUITheme::getContainerBackgroundColor() const -> color
    {
        return colors::make_white();
    }

    auto LightAmatistaUITheme::getContainerForegroundColor() const -> color
    {
        return colors::make_black();
    }

    auto LightAmatistaUITheme::getControlBackgroundColor() const -> color
    {
        return color{0xE0, 0xE0, 0xE0};
    }

    auto LightAmatistaUITheme::getControlForegroundColor() const -> color
    {
        return color{0, 49, 83};
    }

    auto LightAmatistaUITheme::getControlHoveredBackgroundColor() const -> color
    {
        return color{0xF0, 0xF0, 0xF0};
    }

    auto LightAmatistaUITheme::getDisabledBackgroundColor() const -> color
    {
        return color{0x60, 0x60, 0x60};
    }

    auto LightAmatistaUITheme::getDisabledForegroundColor() const -> color
    {
        ;return color{160, 160, 160};
    }

    auto LightAmatistaUITheme::getButtonPressedBackgroundColor() const -> color
    {
        return color{192, 192, 192};
    }

}