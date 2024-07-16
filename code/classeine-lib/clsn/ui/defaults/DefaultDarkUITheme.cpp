#include "DefaultDarkUITheme.h"

#include "clsn/draw/Colors.h"

namespace clsn::ui::defaults
{
    DefaultDarkUITheme::DefaultDarkUITheme()
    {
        add("", "bevelUpColor", Color{0, 92, 155 });
        add("", "bevelDownColor", Color{0, 49, 83 });
        add("", "containerBackgroundColor", Color{0, 25, 42});
        add("", "containerForegroundColor", Colors::makeWhite());
        add("", "controlBackgroundColor", Color{0, 49, 83});
        add("", "controlForegroundColor", Color{240, 240, 250});
        add("", "disabledBackgroundColor", Color{0x60, 0x60, 0x60});
        add("", "disabledForegroundColor", Color{0, 25, 42});

        add("", "font", Font{"Nimbus", FontStyle::REGULAR, 14});

        add("button", "pressedBackgroundColor", Color{0, 35, 60});
    }
}