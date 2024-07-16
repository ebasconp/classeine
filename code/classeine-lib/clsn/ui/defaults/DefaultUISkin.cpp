#include "clsn/ui/defaults/DefaultUISkin.h"

#include "clsn/ui/defaults/DefaultDarkUITheme.h"
#include "clsn/ui/defaults/DefaultLightUITheme.h"

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
#include "clsn/ui/renderers/HBoxContainerRenderer.h"
#include "clsn/ui/renderers/LabelRenderer.h"
#include "clsn/ui/renderers/RadioButtonRenderer.h"
#include "clsn/ui/renderers/ToggleButtonRenderer.h"
#include "clsn/ui/renderers/VBoxContainerRenderer.h"
#include "clsn/ui/renderers/XYContainerRenderer.h"

namespace
{
    using namespace clsn::ui;

    void loadRenderers(defaults::DefaultUISkin& skin)
    {
        skin.makeRendererAndAdd<Button, ButtonRenderer>();
        skin.makeRendererAndAdd<CheckBox, CheckBoxRenderer>();
        skin.makeRendererAndAdd<HBoxContainer, HBoxContainerRenderer>();
        skin.makeRendererAndAdd<Label, LabelRenderer>();
        skin.makeRendererAndAdd<RadioButton, RadioButtonRenderer>();
        skin.makeRendererAndAdd<ToggleButton, ToggleButtonRenderer>();
        skin.makeRendererAndAdd<VBoxContainer, VBoxContainerRenderer>();
        skin.makeRendererAndAdd<XYContainer, XYContainerRenderer>();
    }

    void loadThemes(defaults::DefaultUISkin& skin)
    {
        skin.makeThemeAndAdd<defaults::DefaultLightUITheme>("light");
        skin.makeThemeAndAdd<defaults::DefaultDarkUITheme>("dark");

        skin.installThemeByName("dark");
    }
}

namespace clsn::ui::defaults
{
    DefaultUISkin::DefaultUISkin()
    {
        using namespace clsn::ui;
        using namespace clsn::ui::renderers;

        loadRenderers(*this);
        loadThemes(*this);
    }
}