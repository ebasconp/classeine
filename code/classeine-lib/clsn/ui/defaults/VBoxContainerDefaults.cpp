#include "VBoxContainerDefaults.h"

#include "clsn/ui/renderers/VBoxContainerRenderer.h"

namespace clsn::ui::defaults::VBoxContainerDefaults
{
    using namespace clsn::draw;

    using namespace clsn::ui::renderers;

    void populateDefaults(clsn::ui::UIManagerDefaults& defaults)
    {
        defaults.set("VBoxContainer", "renderer", makeLazyRenderer<VBoxContainerRenderer>());
    }
}