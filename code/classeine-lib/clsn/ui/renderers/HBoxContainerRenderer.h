#pragma once

#include "clsn/ui/IRenderer.h"

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

    class HBoxContainerRenderer final : public IRenderer
    {
    public:
        void paint(Graphics& graphics,
                   const Region& region,
                   Control& baseControl) override;
    };
}