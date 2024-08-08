#include "ToggleButtonRenderer.h"

#include "clsn/ui/ToggleButton.h"

namespace clsn::ui::renderers
{
    using namespace clsn::draw;
    using namespace clsn::ui;

    auto ToggleButtonRenderer::paintAsPressed(const ClickableControl& button) const -> bool
    {
        return static_cast<const ToggleButton&>(button).is_checked() || button.isPressed();
    }
}