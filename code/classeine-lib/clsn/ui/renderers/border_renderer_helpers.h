#pragma once

#include "clsn/ui/graphics.h"

namespace clsn::draw
{
    class color;
    class region;
}

namespace clsn::ui::renderers::border_renderer_helpers
{
    using namespace clsn::draw;

    void draw_beveled_border(graphics& gr,
                           const region& region,
                           const color& a,
                           const color& b,
                           int depth,
                           bool up);

    void draw_flat_border(graphics& gr,
                   const region& region,
                   const color& b,
                   int depth);
}