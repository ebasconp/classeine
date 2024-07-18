#include "DefaultLightUITheme.h"

#include "clsn/draw/Colors.h"

namespace clsn::ui::defaults
{
    void DefaultLightUITheme::populateDefaults()
    {
        add("", "bevelUpColor", Color{0, 92, 155 });
        add("", "bevelDownColor", Color{0, 49, 83 });
        add("", "containerBackgroundColor", Colors::makeWhite());
        add("", "containerForegroundColor", Colors::makeBlack());
        add("", "controlBackgroundColor", Color{0xE0, 0xE0, 0xE0});
        add("", "controlForegroundColor", Color{0, 49, 83});
        add("", "disabledBackgroundColor", Color{0x60, 0x60, 0x60});
        add("", "disabledForegroundColor", Color{160, 160, 160});

        add("", "font", Font{"Nimbus", FontStyle::REGULAR, 14});

        add("Button", "pressedBackgroundColor", Color{192, 192, 192});
        add("Button", "preferredSize", Dimension{96, 32});
    }
}