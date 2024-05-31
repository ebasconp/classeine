#pragma once

#include "clsn/ui/Graphics.h"
#include "clsn/ui/VBoxContainer.h"

#include "clsn/ui/renderers/IRenderer.h"

#include "clsn/draw/Colors.h"
#include "clsn/draw/Region.h"

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

    class VBoxContainerRenderer final : public IRenderer
    {
    public:
        void paint(Graphics& graphics,
                   const Region& region,
                   Control& baseControl) override
        {
            auto& container = static_cast<VBoxContainer&>(baseControl);

            const auto count = container.getVisibleCount();
            if (count == 0)
            {
                graphics.setDrawColor(container.getBackgroundColor());
                graphics.drawFillRectangle(region);
                return;
            }

            const auto regionHeight = region.getHeight() / count;
            for (int i = 0; i < count; i++)
            {
                Region controlRegion{region.getX(), i * regionHeight, region.getWidth(), regionHeight};

                if (container[i].isInvalidated())
                {
                    container[i].paint(graphics, controlRegion);
                    container[i].setInvalidated(false);
                }
            }
        }
    };
}