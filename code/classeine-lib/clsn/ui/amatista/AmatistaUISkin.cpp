#include "clsn/ui/amatista/AmatistaUISkin.h"

#include "clsn/ui/amatista/DarkAmatistaUITheme.h"
#include "clsn/ui/amatista/LightAmatistaUITheme.h"

#include "clsn/ui/Button.h"
#include "clsn/ui/CheckBox.h"
#include "clsn/ui/HBoxContainer.h"
#include "clsn/ui/Label.h"
#include "clsn/ui/RadioButton.h"
#include "clsn/ui/ToggleButton.h"
#include "clsn/ui/VBoxContainer.h"
#include "clsn/ui/XYContainer.h"

#include "clsn/ui/renderers/ButtonRenderer.h"
#include "clsn/ui/renderers/CheckBoxRenderer.h"
#include "clsn/ui/renderers/DualContainerRenderer.h"
#include "clsn/ui/renderers/HBoxContainerRenderer.h"
#include "clsn/ui/renderers/LabelRenderer.h"
#include "clsn/ui/renderers/RadioButtonRenderer.h"
#include "clsn/ui/renderers/ToggleButtonRenderer.h"
#include "clsn/ui/renderers/VBoxContainerRenderer.h"
#include "clsn/ui/renderers/XYContainerRenderer.h"

namespace
{
    using namespace clsn::ui;

    void loadRenderers(amatista::AmatistaUISkin& skin)
    {
        skin.makeRendererAndAdd<Button, ButtonRenderer>();
        skin.makeRendererAndAdd<CheckBox, CheckBoxRenderer>();
        skin.makeRendererAndAdd<DualContainer, DualContainerRenderer>();
        skin.makeRendererAndAdd<HBoxContainer, HBoxContainerRenderer>();
        skin.makeRendererAndAdd<Label, LabelRenderer>();
        skin.makeRendererAndAdd<RadioButton, RadioButtonRenderer>();
        skin.makeRendererAndAdd<ToggleButton, ToggleButtonRenderer>();
        skin.makeRendererAndAdd<VBoxContainer, VBoxContainerRenderer>();
        skin.makeRendererAndAdd<XYContainer, XYContainerRenderer>();
    }

    void loadThemes(amatista::AmatistaUISkin& skin)
    {
        skin.makeThemeAndAdd<amatista::LightAmatistaUITheme>("light");
        skin.makeThemeAndAdd<amatista::DarkAmatistaUITheme>("dark");

        skin.installThemeByName("dark");
    }
}

namespace clsn::ui::amatista
{
    AmatistaUISkin::AmatistaUISkin()
    {
        using namespace clsn::ui;
        using namespace clsn::ui::renderers;

        loadRenderers(*this);
        loadThemes(*this);
    }
}