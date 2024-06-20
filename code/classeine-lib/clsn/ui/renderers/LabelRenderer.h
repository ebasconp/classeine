#pragma once

#include "clsn/ui/IRenderer.h"

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

    class LabelRenderer : public IRenderer
    {
    public:
        void paint(Graphics& graphics,
                   const Region& region,
                   const Control& control) const override;

        void doLayout(Control &control) const override;
    };
}