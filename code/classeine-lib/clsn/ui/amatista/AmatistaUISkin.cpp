#include "clsn/ui/amatista/AmatistaUISkin.h"

#include "clsn/ui/amatista/DarkAmatistaUITheme.h"
#include "clsn/ui/amatista/LightAmatistaUITheme.h"

#include "clsn/ui/button.h"
#include "clsn/ui/check_box.h"
#include "clsn/ui/FlowContainer.h"
#include "clsn/ui/HBoxContainer.h"
#include "clsn/ui/label.h"
#include "clsn/ui/radio_button.h"
#include "clsn/ui/toggle_button.h"
#include "clsn/ui/VBoxContainer.h"
#include "clsn/ui/XYContainer.h"

#include "clsn/ui/renderers/ButtonRenderer.h"
#include "clsn/ui/renderers/CheckBoxRenderer.h"
#include "clsn/ui/renderers/DualContainerRenderer.h"
#include "clsn/ui/renderers/FlowContainerRenderer.h"
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
        skin.makeRendererAndAdd<button, ButtonRenderer>();
        skin.makeRendererAndAdd<check_box, CheckBoxRenderer>();
        skin.makeRendererAndAdd<DualContainer, DualContainerRenderer>();
        skin.makeRendererAndAdd<FlowContainer, FlowContainerRenderer>();
        skin.makeRendererAndAdd<HBoxContainer, HBoxContainerRenderer>();
        skin.makeRendererAndAdd<label, LabelRenderer>();
        skin.makeRendererAndAdd<radio_button, RadioButtonRenderer>();
        skin.makeRendererAndAdd<toggle_button, ToggleButtonRenderer>();
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