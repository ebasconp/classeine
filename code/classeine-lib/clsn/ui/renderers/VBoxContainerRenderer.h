#pragma once

#include "clsn/ui/Graphics.h"

#include "clsn/draw/Colors.h"
#include "clsn/draw/Region.h"

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

    class VBoxContainerRenderer final
    {
    public:
        template <typename ContainerType>
        void paint(Graphics& graphics,
                   const Region& region,
                   ContainerType& container)
        {
            const auto count = container.getModel().getVisibleCount();
            if (count == 0)
            {
                graphics.setDrawColor(container.getBackgroundColor());
                graphics.drawFillRectangle(region);
                return;
            }

            auto& model = container.getModel();
            const auto regionHeight = region.getHeight() / count;
            for (int i = 0; i < count; i++)
            {
                Region controlRegion{region.getX(), i * regionHeight, region.getWidth(), regionHeight};

                if (model[i].isInvalidated())
                {
                    model[i].paint(graphics, controlRegion);
                    model[i].setInvalidated(false);
                }
            }
        }
    };
}