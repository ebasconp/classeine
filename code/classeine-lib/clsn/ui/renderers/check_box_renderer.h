#pragma once

#include "clsn/ui/renderers/label_renderer.h"

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

    class check_box_renderer : public renderer_base
    {
        label_renderer m_labelRenderer;

    public:
        void paint(graphics& graphics,
                   const region& region,
                   const control& baseControl) const override;
    };
}