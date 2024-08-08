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

namespace clsn::ui::renderers::LabelRendererHelpers
{
    using namespace clsn::draw;

    void drawControlText(graphics& graphics, const control& control, const region& region);
}