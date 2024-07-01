#include "LabelDefaults.h"

#include "clsn/ui/renderers/LabelRenderer.h"

namespace clsn::ui::defaults::LabelDefaults
{
    using namespace clsn::draw;

    using namespace clsn::ui::renderers;

    void populateDefaults(clsn::ui::UIManagerDefaults& defaults)
    {
        defaults.set("Label", "renderer", makeLazyRenderer<LabelRenderer>());
    }
}