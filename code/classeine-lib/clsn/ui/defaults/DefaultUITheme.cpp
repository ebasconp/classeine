#include "DefaultUITheme.h"

#include "clsn/draw/Colors.h"

namespace clsn::ui::defaults
{
    void DefaultUITheme::populateDefaults()
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

    auto DefaultUITheme::getDefaultFont() const -> Font
    {
        return Font{"Nimbus", FontStyle::REGULAR, 14};
    }

    auto DefaultUITheme::getButtonPreferredSize() const -> Dimension
    {
        return Dimension{96, 32};
    }
}