#pragma once

#include "clsn/ui/Graphics.h"

namespace clsn::draw
{
    class Color;
    class Region;
}

namespace clsn::ui::renderers::BorderRendererHelpers
{
    using namespace clsn::draw;

    void drawBeveledBorder(Graphics& gr,
                           const Region& region,
                           const Color& a,
                           const Color& b,
                           int depth,
                           bool up);

    void drawFlatBorder(Graphics& gr,
                   const Region& region,
                   const Color& a,
                   const Color& b,
                   int depth,
                   bool up);
}