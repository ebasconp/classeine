#pragma once

#include "clsn/draw/region.h"

#include "clsn/ui/IRenderer.h"

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

    template <typename ContainerType>
    class ContainerRenderer : public IRenderer
    {
    public:
        void paint(Graphics& graphics,
                   const region& a_region,
                   const Control& baseControl) const override
        {
            auto& container =
                static_cast<const ContainerType&>(baseControl);

            const auto visibleCount = container.getVisibleCount();
            if (visibleCount == 0)
            {
                graphics.setDrawColor(container.getActualBackgroundColor());
                graphics.drawFillRectangle(a_region);
                return;
            }

            const auto count = container.getCount();
            for (int i = 0; i < count; i++)
            {
                auto& control = container[i];
                if (!control.is_visible() || !control.isInvalidated())
                    continue;

                region controlRegion{
                    control.get_actual_position(),
                    control.get_actual_size()}; // ETOTODOcontrol.getBounds();

                control.paint(graphics, controlRegion);
                control.validate();
            }
        }
    };
}