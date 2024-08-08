#pragma once

#include "clsn/ui/xy_container.h"

#include "clsn/ui/renderers/ContainerRenderer.h"

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

    class XYContainerRenderer final : public ContainerRenderer<xy_container>
    {
    public:
        void paint(graphics& graphics, const region& region,
                   const control& baseControl) const override;
    };
}