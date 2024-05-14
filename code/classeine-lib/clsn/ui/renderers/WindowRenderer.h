#pragma once

#include <iostream> //ETOTODO

#include "clsn/ui/Graphics.h"

namespace clsn::ui::renderers
{
    class WindowRenderer
    {
    public:
        template <typename ControlType>
        void paint(Graphics& graphics, const ControlType& window)
        {
            window.getControl().paint(graphics);
        }
    };
};