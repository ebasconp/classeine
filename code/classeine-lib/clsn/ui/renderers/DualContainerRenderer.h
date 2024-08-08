#pragma once

#include "clsn/ui/DualContainer.h"

#include "clsn/ui/renderers/ContainerRenderer.h"

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

    class DualContainerRenderer final : public ContainerRenderer<DualContainer>
    {
    public:
        void paint(Graphics& graphics, const region& region,
                   const Control& baseControl) const override;
    };
}