#pragma once

#include "clsn/ui/renderer_base.h"

namespace clsn::ui::renderers
{
    class null_renderer : public renderer_base
    {
    public:
        void paint(graphics&, const region&, const control&) const override
        {
            // Nothing to do here
        }
    };
}