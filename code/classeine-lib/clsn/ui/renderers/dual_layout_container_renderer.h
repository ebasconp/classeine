#pragma once

#include "clsn/ui/dual_layout_container.h"

#include "clsn/ui/renderers/container_renderer.h"

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

    class dual_layout_container_renderer final : public container_renderer<dual_layout_container>
    {
    public:
        void paint(graphics& graphics, const region& region,
                   const control& baseControl) const override;
    };
}