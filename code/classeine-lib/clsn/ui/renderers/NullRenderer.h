#pragma once

#include "clsn/ui/IRenderer.h"

namespace clsn::ui::renderers
{
    class NullRenderer : public IRenderer
    {
    public:
        void paint(Graphics&, const region&, const Control&) const override
        {
            // Nothing to do here
        }
    };
}