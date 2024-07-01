#include "XYContainerDefaults.h"

#include "clsn/ui/renderers/XYContainerRenderer.h"

namespace clsn::ui::defaults::XYContainerDefaults
{
    using namespace clsn::draw;

    using namespace clsn::ui::renderers;

    void populateDefaults(clsn::ui::UIManagerDefaults& defaults)
    {
        defaults.set("XYContainer", "renderer", makeLazyRenderer<XYContainerRenderer>());
    }
}