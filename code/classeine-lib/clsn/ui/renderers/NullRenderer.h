#pragma once

#include "clsn/ui/IRenderer.h"

namespace clsn::ui::renderers
{
    class NullRenderer : public IRenderer
    {
    public:
        void paint(graphics&, const region&, const control&) const override
        {
            // Nothing to do here
        }
    };
}