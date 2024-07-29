#pragma once

#include "clsn/ui/XYContainer.h"

#include "clsn/ui/renderers/ContainerRenderer.h"

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

    class XYContainerRenderer final : public ContainerRenderer<XYContainer>
    {
    public:
        void paint(Graphics& graphics, const Region& region,
                   const Control& baseControl) const override;
    };
}