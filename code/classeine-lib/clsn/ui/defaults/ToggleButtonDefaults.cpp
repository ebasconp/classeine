#include "ToggleButtonDefaults.h"

#include "clsn/ui/renderers/ToggleButtonRenderer.h"

namespace clsn::ui::defaults::ToggleButtonDefaults
{
    using namespace clsn::draw;

    using namespace clsn::ui::renderers;

    void populateDefaults(clsn::ui::UIManagerDefaults& defaults)
    {
        defaults.set("ToggleButton", "renderer", makeLazyRenderer<ToggleButtonRenderer>());
    }
}