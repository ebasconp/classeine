#include "ThemeDefaults.h"

#include "clsn/draw/Colors.h"
#include "clsn/draw/Font.h"

namespace clsn::ui::defaults::ThemeDefaults
{
    using namespace clsn::draw;

    void populateDefaults(UIManagerDefaults& defaults)
    {
        defaults.set("Theme", "bevelUpColor", Color{0xE0, 0xE0, 0xE0});
        defaults.set("Theme", "bevelDownColor", Color{0x60, 0x60, 0x60});
        defaults.set("Theme", "containerBackgroundColor", Color{0xF0, 0xF0, 0xF0});
        defaults.set("Theme", "containerForegroundColor", Colors::makeBlack());
        defaults.set("Theme", "controlBackgroundColor", Color{0xE0, 0xE0, 0xE0});
        defaults.set("Theme", "controlForegroundColor", Colors::makeBlack());
        defaults.set("Theme", "disabledBackgroundColor", Color{0x60, 0x60, 0x60});
        defaults.set("Theme", "disabledForegroundColor", Color{0x40, 0x40, 0x40});

        defaults.set(
            "Theme", "font", Font("Nimbus", FontStyle::REGULAR, 14));
    }
}