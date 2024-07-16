#include "DefaultDarkUITheme.h"

#include "clsn/draw/Colors.h"

namespace clsn::ui::defaults
{
    DefaultDarkUITheme::DefaultDarkUITheme()
    {
        addColor("", "bevelUpColor", Color{0, 92, 155 });
        addColor("", "bevelDownColor", Color{0, 49, 83 });
        addColor("", "containerBackgroundColor", Color{0, 25, 42});
        addColor("", "containerForegroundColor", Colors::makeWhite());
        addColor("", "controlBackgroundColor", Color{0, 49, 83});
        addColor("", "controlForegroundColor", Color{240, 240, 250});
        addColor("", "disabledBackgroundColor", Color{0x60, 0x60, 0x60});
        addColor("", "disabledForegroundColor", Color{0, 25, 42});

        addColor("button", "pressedBackgroundColor", Color{0, 35, 60});
    }
}