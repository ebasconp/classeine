#pragma once

#include "clsn/ui/flow_layout_container.h"

#include "clsn/ui/renderers/container_renderer.h"

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

    class flow_container_renderer final : public container_renderer<flow_layout_container>
    {
    public:
        void paint(graphics& graphics, const region& region,
                   const control& baseControl) const override;
    };
}