#include "clsn/ui/defaults/DefaultUISkin.h"

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


namespace clsn::ui::defaults
{
    DefaultUISkin::DefaultUISkin()
    {
        using namespace clsn::ui;
        using namespace clsn::ui::renderers;

        makeAndAdd<Button, ButtonRenderer>();
        makeAndAdd<CheckBox, CheckBoxRenderer>();
        makeAndAdd<HBoxContainer, HBoxContainerRenderer>();
        makeAndAdd<Label, LabelRenderer>();
        makeAndAdd<RadioButton, RadioButtonRenderer>();
        makeAndAdd<ToggleButton, ToggleButtonRenderer>();
        makeAndAdd<VBoxContainer, VBoxContainerRenderer>();
        makeAndAdd<XYContainer, XYContainerRenderer>();
    }
}