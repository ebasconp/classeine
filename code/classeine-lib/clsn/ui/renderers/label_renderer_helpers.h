#pragma once

#include "clsn/ui/graphics.h"

#include <string_view>

namespace clsn::draw
{
    class region;
}

namespace clsn::ui
{
    class control;
}

namespace clsn::ui::renderers::label_renderer_helpers
{
    using namespace clsn::draw;

    void draw_control_text(graphics& graphics, const control& control, const region& region);
}