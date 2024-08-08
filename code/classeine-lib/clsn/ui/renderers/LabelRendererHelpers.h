#pragma once

#include "clsn/ui/Graphics.h"

#include <string_view>

namespace clsn::draw
{
    class region;
}

namespace clsn::ui
{
    class Control;
}

namespace clsn::ui::renderers::LabelRendererHelpers
{
    using namespace clsn::draw;

    void drawControlText(Graphics& graphics, const Control& control, const region& region);
}