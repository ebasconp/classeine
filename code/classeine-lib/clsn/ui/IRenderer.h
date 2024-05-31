#pragma once

#include "clsn/ui/Graphics.h"

namespace clsn::draw
{
    class Region;
}

namespace clsn::ui
{
    class Control;
}

namespace clsn::ui
{
    using namespace clsn::draw;

    class IRenderer
    {
    public:
        virtual ~IRenderer() = default;

        virtual void paint(Graphics& graphics,
                           const Region& region,
                           const Control& baseControl) const = 0;
    };
}