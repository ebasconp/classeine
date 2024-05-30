#pragma once

#include "clsn/ui/Graphics.h"

#include "clsn/draw/Colors.h"
#include "clsn/draw/Region.h"

#include "BorderRenderer.h"

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

    class DefaultLabelRenderer
    {
    public:
        template <typename Control>
        void paint(Graphics& graphics,
                   const Region& region,
                   const Control& control)
        {
            graphics.drawText(region,
                              control.getFont(),
                              control.isEnabled()
                                  ? control.getForegroundColor()
                                  : UIManager::getInstance().getDefault<Color>(
                                        "Theme", "disabledForegroundColor"),
                              control.getText());
        }
    };
}