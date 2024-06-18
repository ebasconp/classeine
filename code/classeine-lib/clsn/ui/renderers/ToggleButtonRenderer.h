#pragma once

#include "BorderRenderer.h"
#include "ButtonRenderer.h"

#include "clsn/ui/Graphics.h"
#include "clsn/ui/ToggleButton.h"

#include "clsn/draw/Region.h"

#include "clsn/ui/IRenderer.h"

namespace clsn::ui::renderers
{
    using namespace clsn::draw;
    using namespace clsn::ui;

    template <typename LabelRendererType>
    class ToggleButtonRenderer : public ButtonRenderer<LabelRendererType>
    {
    public:
        [[nodiscard]] virtual auto paintAsPressed(const ClickableControl& button) const -> bool
        {
            return static_cast<const ToggleButton&>(button).isChecked();
        }
    };
}