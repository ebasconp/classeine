#include "ThemeDefaults.h"

#include "clsn/draw/Color.h"
#include "clsn/draw/Colors.h"
#include "clsn/draw/Font.h"

namespace clsn::ui::defaults::ThemeDefaults
{
    using namespace clsn::draw;

    void populateDefaults(UIManagerDefaults& defaults)
    {
        defaults.set("Theme", "bevelUpColor", Color{0xA0, 0xA8, 0xAF});
        defaults.set("Theme", "bevelDownColor", Color{0x50, 0x58, 0x5F});
        defaults.set("Theme", "backgroundColor", Color{0x70, 0x78, 0x7F});
        defaults.set("Theme", "foregroundColor", Colors::WHITE);

        defaults.set("Theme", "controlFont", Font("Arial", 12));

    }
}