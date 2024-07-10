#pragma once

#include "ButtonRenderer.h"

namespace  clsn::ui
{
    class ClickableControl;
}

namespace clsn::ui::renderers
{
    using namespace clsn::draw;
    using namespace clsn::ui;

    class ToggleButtonRenderer : public ButtonRenderer
    {
    public:
        [[nodiscard]] virtual auto paintAsPressed(const ClickableControl& button) const -> bool;
    };
}