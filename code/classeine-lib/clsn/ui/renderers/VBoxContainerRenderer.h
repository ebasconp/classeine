#pragma once

#include "clsn/ui/renderers/ContainerRenderer.h"

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

    class VBoxContainerRenderer final : public ContainerRenderer
    {
    public:
        void doLayout(Control& control) const override;
    };
}