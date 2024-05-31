#pragma once

#include "clsn/ui/IRenderer.h"

namespace clsn::ui::renderers
{
    class NullRenderer : public IRenderer
    {
    public:
        void paint(Graphics& graphics,
                   const Region& region,
                   const Control& baseControl) const override
        {
            // Nothing to do here
        }
    };
}