#pragma once

#include "clsn/ui/renderers/ContainerRenderer.h"

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

    class HBoxContainerRenderer final : public ContainerRenderer
    {
    public:
        void doLayout(Control& baseControl) const override;
    };
}