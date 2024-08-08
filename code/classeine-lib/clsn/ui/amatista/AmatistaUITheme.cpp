#include "AmatistaUITheme.h"

#include "clsn/draw/colors.h"

namespace clsn::ui::amatista
{
    void AmatistaUITheme::populateDefaults()
    {
        add("", "bevelUpColor", getBevelUpColor());
        add("", "bevelDownColor", getBevelDownColor());
        add("", "containerBackgroundColor", getContainerBackgroundColor());
        add("", "containerForegroundColor", getContainerForegroundColor());
        add("", "controlBackgroundColor", getControlBackgroundColor());
        add("", "controlForegroundColor", getControlForegroundColor());
        add("", "controlHoveredBackgroundColor", getControlHoveredBackgroundColor());
        add("", "disabledBackgroundColor", getDisabledBackgroundColor());
        add("", "disabledForegroundColor", getDisabledForegroundColor());

        add("", "defaultFont", getDefaultFont());

        add("Button", "pressedBackgroundColor", getButtonPressedBackgroundColor());
        add("Button", "preferredSize", getButtonPreferredSize());
    }

    auto AmatistaUITheme::getDefaultFont() const -> font
    {
        return font{"Nimbus", font_style::regular, 14};
    }

    auto AmatistaUITheme::getButtonPreferredSize() const -> dimension
    {
        return dimension{96, 32};
    }
}