#include "ButtonDefaults.h"

#include "clsn/ui/renderers/VBoxContainerRenderer.h"

#include <memory>

namespace clsn::ui::defaults::VBoxContainerDefaults
{
    using namespace clsn::draw;

    using namespace clsn::ui::renderers;

    void populateDefaults(clsn::ui::UIManagerDefaults& defaults)
    {
        defaults.set("VBoxContainer", "renderer", std::make_shared<VBoxContainerRenderer>());
    }
}