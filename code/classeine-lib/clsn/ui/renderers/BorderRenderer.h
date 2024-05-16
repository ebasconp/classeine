#pragma once

#include "clsn/draw/Color.h"

#include "clsn/ui/Graphics.h"

namespace clsn::draw
{
    class Region;
}

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

    class BorderRenderer
    {
    public:
        void drawBeveledBorder(Graphics& gr,
                               const Region& region,
                               const Color& a,
                               const Color& b,
                               int depth,
                               bool up);
    };
}