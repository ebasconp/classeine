#pragma once

#include "clsn/ui/renderers/LabelRenderer.h"

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

    class RadioButtonRenderer : public IRenderer
    {
        LabelRenderer m_labelRenderer;

    public:
        void paint(Graphics& graphics,
                   const region& region,
                   const Control& baseControl) const override;
    };
}