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

namespace clsn::ui::renderers
{
    using namespace clsn::draw;
    using namespace clsn::ui;

    class IRenderer
    {
    public:
        virtual ~IRenderer() = default;

        virtual void paint(Graphics& graphics, const Region& region, Control& baseControl) = 0;
    };
}