#pragma once

#include "clsn/ui/renderer_base.h"

namespace clsn::ui
{
  class clickable_control;
}

namespace clsn::ui::renderers
{
    using namespace clsn::draw;
    using namespace clsn::ui;

    class button_renderer : public renderer_base
    {
    public:
        [[nodiscard]] virtual auto paint_as_pressed(const clickable_control& button) const -> bool;

        void paint(graphics& graphics,
                   const region& region,
                   const control& baseControl) const override;
    };
}