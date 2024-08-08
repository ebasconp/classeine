#pragma once

#include "clsn/ui/IRenderer.h"

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

    class LabelRenderer : public IRenderer
    {
    public:
        void paint(graphics& graphics,
                   const region& region,
                   const control& control) const override;
    };
}