#include "ButtonDefaults.h"

#include "clsn/ui/renderers/HBoxContainerRenderer.h"

namespace clsn::ui::defaults::HBoxContainerDefaults
{
    using namespace clsn::draw;

    using namespace clsn::ui::renderers;

    void populateDefaults(clsn::ui::UIManagerDefaults& defaults)
    {
        defaults.set("HBoxContainer", "renderer", makeLazyRenderer<HBoxContainerRenderer>());
    }
}