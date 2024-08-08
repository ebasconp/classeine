#pragma once

#include "clsn/ui/graphics.h"

namespace clsn::draw
{
    class color;
    class region;
}

namespace clsn::ui::renderers::BorderRendererHelpers
{
    using namespace clsn::draw;

    void drawBeveledBorder(graphics& gr,
                           const region& region,
                           const color& a,
                           const color& b,
                           int depth,
                           bool up);

    void drawFlatBorder(graphics& gr,
                   const region& region,
                   const color& a,
                   const color& b,
                   int depth,
                   bool up);
}