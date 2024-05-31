#pragma once

#include "clsn/ui/IRenderer.h"

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

    class VBoxContainerRenderer final : public IRenderer
    {
    public:
        void paint(Graphics& graphics,
                   const Region& region,
                   const Control& baseControl) const override;
    };
}