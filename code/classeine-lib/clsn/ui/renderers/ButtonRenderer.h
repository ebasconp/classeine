#pragma once

#include "clsn/ui/IRenderer.h"

namespace clsn::ui
{
  class ClickableControl;
}

namespace clsn::ui::renderers
{
    using namespace clsn::draw;
    using namespace clsn::ui;

    class ButtonRenderer : public IRenderer
    {
    public:
        [[nodiscard]] virtual auto paintAsPressed(const ClickableControl& button) const -> bool;

        void paint(Graphics& graphics,
                   const region& region,
                   const Control& baseControl) const override;
    };
}