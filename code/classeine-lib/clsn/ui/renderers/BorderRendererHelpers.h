#pragma once

#include "clsn/ui/Graphics.h"

namespace clsn::draw
{
    class color;
    class region;
}

namespace clsn::ui::renderers::BorderRendererHelpers
{
    using namespace clsn::draw;

    void drawBeveledBorder(Graphics& gr,
                           const region& region,
                           const color& a,
                           const color& b,
                           int depth,
                           bool up);

    void drawFlatBorder(Graphics& gr,
                   const region& region,
                   const color& a,
                   const color& b,
                   int depth,
                   bool up);
}