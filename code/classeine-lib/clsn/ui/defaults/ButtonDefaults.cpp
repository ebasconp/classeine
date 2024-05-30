#include "ButtonDefaults.h"

#include "clsn/ui/renderers/ButtonRenderer.h"
#include "clsn/ui/renderers/LabelRenderer.h"

#include <memory>

namespace clsn::ui::defaults::ButtonDefaults
{
    using namespace clsn::draw;

    using namespace clsn::ui::renderers;

    void populateDefaults(clsn::ui::UIManagerDefaults& defaults)
    {
        defaults.set("Button", "renderer", std::make_shared<ButtonRenderer<DefaultLabelRenderer>>());
    }
}