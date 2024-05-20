#pragma once

#include "clsn/ui/Graphics.h"

#include "clsn/draw/Colors.h"
#include "clsn/draw/Region.h"

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

    class HBoxContainerRenderer final
    {
    public:
        template <typename ContainerType>
        void paint(Graphics& graphics,
                   const Region& region,
                   ContainerType& container)
        {
            graphics.setDrawColor(container.getBackgroundColor());
            graphics.drawFillRectangle(region);

            const auto count = container.getModel().getCount();
            if (count == 0)
                return;

            auto& model = container.getModel();
            const auto regionWidth = region.getWidth() / count;
            for (int i = 0; i < count; i++)
            {
                Region controlRegion{(i * regionWidth) + region.getX(), region.getY(), regionWidth, region.getHeight()};
                model[i].paint(graphics, controlRegion);
            }
        }
    };
}