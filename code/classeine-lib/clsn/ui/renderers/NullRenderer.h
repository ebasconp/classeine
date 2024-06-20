#pragma once

#include "clsn/ui/IRenderer.h"

namespace clsn::ui::renderers
{
    class NullRenderer : public IRenderer
    {
    public:
        void paint(Graphics&, const Region&, const Control&) const override
        {
            // Nothing to do here
        }

        void doLayout(Control&) const override
        {
            // Nothing to do here
        }
    };
}