#include "DefaultLightUITheme.h"

#include "clsn/draw/Colors.h"

namespace clsn::ui::defaults
{
    auto DefaultLightUITheme::getBevelUpColor() const -> Color
    {
        return Color{0, 92, 155 };
    }

    auto DefaultLightUITheme::getBevelDownColor() const -> Color
    {
        return Color{0, 49, 83 };
    }

    auto DefaultLightUITheme::getContainerBackgroundColor() const -> Color
    {
        return Colors::makeWhite();
    }

    auto DefaultLightUITheme::getContainerForegroundColor() const -> Color
    {
        return Colors::makeBlack();
    }

    auto DefaultLightUITheme::getControlBackgroundColor() const -> Color
    {
        return Color{0xE0, 0xE0, 0xE0};
    }

    auto DefaultLightUITheme::getControlForegroundColor() const -> Color
    {
        return Color{0, 49, 83};
    }

    auto DefaultLightUITheme::getDisabledBackgroundColor() const -> Color
    {
        return Color{0x60, 0x60, 0x60};
    }

    auto DefaultLightUITheme::getDisabledForegroundColor() const -> Color
    {
        ;return Color{160, 160, 160};
    }

    auto DefaultLightUITheme::getButtonPressedBackgroundColor() const -> Color
    {
        return Color{192, 192, 192};
    }

}