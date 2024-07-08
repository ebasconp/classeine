#pragma once

#include "clsn/ui/Graphics.h"

namespace clsn::draw
{
    class Color;
    class Region;
}

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

    class BorderRenderer
    {
    public:
        static void drawBeveledBorder(Graphics& gr,
                               const Region& region,
                               const Color& a,
                               const Color& b,
                               int depth,
                               bool up);

        static void drawFlatBorder(Graphics& gr,
                       const Region& region,
                       const Color& a,
                       const Color& b,
                       int depth,
                       bool up);
    };
}