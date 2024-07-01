#include "RadioButtonDefaults.h"

#include "clsn/ui/renderers/RadioButtonRenderer.h"

namespace clsn::ui::defaults::RadioButtonDefaults
{
    using namespace clsn::draw;

    using namespace clsn::ui::renderers;

    void populateDefaults(clsn::ui::UIManagerDefaults& defaults)
    {
        defaults.set("RadioButton", "renderer", makeLazyRenderer<RadioButtonRenderer>());
    }
}