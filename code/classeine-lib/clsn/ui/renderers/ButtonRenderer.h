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

        void doLayout(Control&) const override;

        void paint(Graphics& graphics,
                   const Region& region,
                   const Control& baseControl) const override;
    };
}