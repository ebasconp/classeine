#pragma once

#include "clsn/ui/IRenderer.h"

namespace clsn::ui
{
  class clickable_control;
}

namespace clsn::ui::renderers
{
    using namespace clsn::draw;
    using namespace clsn::ui;

    class ButtonRenderer : public IRenderer
    {
    public:
        [[nodiscard]] virtual auto paintAsPressed(const clickable_control& button) const -> bool;

        void paint(graphics& graphics,
                   const region& region,
                   const control& baseControl) const override;
    };
}