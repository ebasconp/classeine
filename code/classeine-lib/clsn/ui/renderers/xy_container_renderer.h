#pragma once

#include "clsn/ui/xy_container.h"

#include "clsn/ui/renderers/container_renderer.h"

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

    class xy_container_renderer final : public container_renderer<xy_container>
    {
    public:
        void paint(graphics& graphics, const region& region,
                   const control& baseControl) const override;
    };
}