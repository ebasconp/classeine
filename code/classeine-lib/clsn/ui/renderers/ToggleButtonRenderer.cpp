#include "ToggleButtonRenderer.h"

#include "clsn/ui/toggle_button.h"

namespace clsn::ui::renderers
{
    using namespace clsn::draw;
    using namespace clsn::ui;

    auto ToggleButtonRenderer::paintAsPressed(const clickable_control& button) const -> bool
    {
        return static_cast<const toggle_button&>(button).is_checked() || button.is_pressed();
    }
}