#pragma once

#include "clsn/ui/renderers/LabelRenderer.h"

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

    class CheckBoxRenderer : public IRenderer
    {
        LabelRenderer m_labelRenderer;

    public:
        void paint(graphics& graphics,
                   const region& region,
                   const control& baseControl) const override;
    };
}