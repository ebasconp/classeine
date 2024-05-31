#pragma once

#include "clsn/ui/IRenderer.h"

namespace clsn::ui::renderers
{
    class NullRenderer : public IRenderer
    {
    public:
        void paint(Graphics& graphics, const Region& region, Control& baseControl) override
        {
            // Nothing to do here
        }
    };
}