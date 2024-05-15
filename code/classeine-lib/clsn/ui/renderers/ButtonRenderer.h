#pragma once

#include "clsn/ui/Graphics.h"

#include "clsn/draw/Colors.h"

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

    class ButtonRenderer
    {
    public:
        template <typename Control>
        void paint(Graphics& graphics, const Control& model)
        {
            graphics.setDrawColor(model.getBackgroundColor());
        }
    };
}