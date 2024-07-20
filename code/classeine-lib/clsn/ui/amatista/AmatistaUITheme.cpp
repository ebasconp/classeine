#include "AmatistaUITheme.h"

#include "clsn/draw/Colors.h"

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
        add("", "disabledBackgroundColor", getDisabledBackgroundColor());
        add("", "disabledForegroundColor", getDisabledForegroundColor());

        add("", "defaultFont", getDefaultFont());

        add("Button", "pressedBackgroundColor", getButtonPressedBackgroundColor());
        add("Button", "preferredSize", getButtonPreferredSize());
    }

    auto AmatistaUITheme::getDefaultFont() const -> Font
    {
        return Font{"Nimbus", FontStyle::REGULAR, 14};
    }

    auto AmatistaUITheme::getButtonPreferredSize() const -> Dimension
    {
        return Dimension{96, 32};
    }
}