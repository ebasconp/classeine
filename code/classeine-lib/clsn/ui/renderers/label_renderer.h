#pragma once

#include "clsn/ui/renderer_base.h"

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

    class label_renderer : public renderer_base
    {
    public:
        void paint(graphics& graphics,
                   const region& region,
                   const control& control) const override;
    };
}