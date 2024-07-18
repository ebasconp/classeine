#include "DefaultDarkUITheme.h"

#include "clsn/draw/Colors.h"

namespace clsn::ui::defaults
{
    auto DefaultDarkUITheme::getBevelUpColor() const -> Color
    {
        return Color{0, 92, 155 };
    }

    auto DefaultDarkUITheme::getBevelDownColor() const -> Color
    {
        return Color{0, 49, 83 };
    }

    auto DefaultDarkUITheme::getContainerBackgroundColor() const -> Color
    {
        return Color{0, 25, 42};
    }

    auto DefaultDarkUITheme::getContainerForegroundColor() const -> Color
    {
        return Colors::makeWhite();
    }

    auto DefaultDarkUITheme::getControlBackgroundColor() const -> Color
    {
        return Color{0, 49, 83};
    }

    auto DefaultDarkUITheme::getControlForegroundColor() const -> Color
    {
        return Color{240, 240, 250};
    }

    auto DefaultDarkUITheme::getDisabledBackgroundColor() const -> Color
    {
        return Color{0x60, 0x60, 0x60};
    }

    auto DefaultDarkUITheme::getDisabledForegroundColor() const -> Color
    {
        return Color{0, 25, 42};
    }

    auto DefaultDarkUITheme::getButtonPressedBackgroundColor() const -> Color
    {
        return Color{0, 35, 60};
    }
}