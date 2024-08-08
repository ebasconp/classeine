#include "clsn/ui/amatista/AmatistaUISkin.h"

#include "clsn/ui/amatista/DarkAmatistaUITheme.h"
#include "clsn/ui/amatista/LightAmatistaUITheme.h"

#include "clsn/ui/button.h"
#include "clsn/ui/check_box.h"
#include "clsn/ui/flow_container.h"
#include "clsn/ui/hbox_container.h"
#include "clsn/ui/label.h"
#include "clsn/ui/radio_button.h"
#include "clsn/ui/toggle_button.h"
#include "clsn/ui/vbox_container.h"
#include "clsn/ui/xy_container.h"

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
        skin.make_renderer_and_add<button, ButtonRenderer>();
        skin.make_renderer_and_add<check_box, CheckBoxRenderer>();
        skin.make_renderer_and_add<dual_container, DualContainerRenderer>();
        skin.make_renderer_and_add<flow_container, FlowContainerRenderer>();
        skin.make_renderer_and_add<hbox_container, HBoxContainerRenderer>();
        skin.make_renderer_and_add<label, LabelRenderer>();
        skin.make_renderer_and_add<radio_button, RadioButtonRenderer>();
        skin.make_renderer_and_add<toggle_button, ToggleButtonRenderer>();
        skin.make_renderer_and_add<vbox_container, VBoxContainerRenderer>();
        skin.make_renderer_and_add<xy_container, XYContainerRenderer>();
    }

    void loadThemes(amatista::AmatistaUISkin& skin)
    {
        skin.make_theme_and_add<amatista::LightAmatistaUITheme>("light");
        skin.make_theme_and_add<amatista::DarkAmatistaUITheme>("dark");

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