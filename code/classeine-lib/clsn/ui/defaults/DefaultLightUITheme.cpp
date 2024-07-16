#include "DefaultLightUITheme.h"

#include "clsn/draw/Colors.h"

namespace clsn::ui::defaults
{
    DefaultLightUITheme::DefaultLightUITheme()
    {
        addColor("", "bevelUpColor", Color{0, 92, 155 });
        addColor("", "bevelDownColor", Color{0, 49, 83 });
        addColor("", "containerBackgroundColor", Colors::makeWhite());
        addColor("", "containerForegroundColor", Colors::makeBlack());
        addColor("", "controlBackgroundColor", Color{0xE0, 0xE0, 0xE0});
        addColor("", "controlForegroundColor", Color{0, 49, 83});
        addColor("", "disabledBackgroundColor", Color{0x60, 0x60, 0x60});
        addColor("", "disabledForegroundColor", Color{160, 160, 160});

        addColor("button", "pressedBackgroundColor", Color{192, 192, 192});
    }
}