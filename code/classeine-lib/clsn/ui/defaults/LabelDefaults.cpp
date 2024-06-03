#include "ButtonDefaults.h"

#include "clsn/ui/renderers/LabelRenderer.h"

#include <memory>

namespace clsn::ui::defaults::LabelDefaults
{
    using namespace clsn::draw;

    using namespace clsn::ui::renderers;

    void populateDefaults(clsn::ui::UIManagerDefaults& defaults)
    {
        defaults.set("Label", "renderer", makeLazyRenderer<LabelRenderer>());
    }
}