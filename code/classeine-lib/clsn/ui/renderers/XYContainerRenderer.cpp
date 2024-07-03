#include "XYContainerRenderer.h"


namespace clsn::ui::renderers
{
    void XYContainerRenderer::doLayout(Control& baseControl) const
    {
        auto& container = static_cast<XYContainer&>(baseControl);

        const auto visibleCount = container.getVisibleCount();
        if (visibleCount == 0)
            return;

        const auto position = container.getActualPosition();

        container.iterate([&position](auto& control, auto& constraint)
        {
            if (!control.isVisible())
                return;

            control.setActualPosition({position.getX() + constraint.getX(), position.getY() + constraint.getY()});
            control.setActualSize(constraint.getSize());
        });
    }

    void XYContainerRenderer::paint(Graphics& graphics,
                                  const Region& region,
                                  const Control& baseControl) const
    {
        graphics.setDrawColor(Color{0xFFFF00});
        graphics.drawFillRectangle(region);

        ContainerRenderer::paint(graphics, region, baseControl);
    }
}