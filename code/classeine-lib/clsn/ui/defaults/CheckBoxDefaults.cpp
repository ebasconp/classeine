#include "CheckBoxDefaults.h"

#include "clsn/ui/renderers/CheckBoxRenderer.h"

namespace clsn::ui::defaults::CheckBoxDefaults
{
    using namespace clsn::draw;

    using namespace clsn::ui::renderers;

    void populateDefaults(clsn::ui::UIManagerDefaults& defaults)
    {
        defaults.set("CheckBox", "renderer", makeLazyRenderer<CheckBoxRenderer>());
    }
}