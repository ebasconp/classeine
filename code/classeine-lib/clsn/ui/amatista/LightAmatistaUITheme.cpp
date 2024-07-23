#include "LightAmatistaUITheme.h"

#include "clsn/draw/Colors.h"

namespace clsn::ui::amatista
{
    auto LightAmatistaUITheme::getBevelUpColor() const -> Color
    {
        return Color{0, 92, 155 };
    }

    auto LightAmatistaUITheme::getBevelDownColor() const -> Color
    {
        return Color{0, 49, 83 };
    }

    auto LightAmatistaUITheme::getContainerBackgroundColor() const -> Color
    {
        return Colors::makeWhite();
    }

    auto LightAmatistaUITheme::getContainerForegroundColor() const -> Color
    {
        return Colors::makeBlack();
    }

    auto LightAmatistaUITheme::getControlBackgroundColor() const -> Color
    {
        return Color{0xE0, 0xE0, 0xE0};
    }

    auto LightAmatistaUITheme::getControlForegroundColor() const -> Color
    {
        return Color{0, 49, 83};
    }

    auto LightAmatistaUITheme::getControlHoveredBackgroundColor() const -> Color
    {
        return Color{0xF0, 0xF0, 0xF0};
    }

    auto LightAmatistaUITheme::getDisabledBackgroundColor() const -> Color
    {
        return Color{0x60, 0x60, 0x60};
    }

    auto LightAmatistaUITheme::getDisabledForegroundColor() const -> Color
    {
        ;return Color{160, 160, 160};
    }

    auto LightAmatistaUITheme::getButtonPressedBackgroundColor() const -> Color
    {
        return Color{192, 192, 192};
    }

}