#pragma once

#include "clsn/ui/VBoxContainer.h"

#include "clsn/ui/renderers/ContainerRenderer.h"

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

    class VBoxContainerRenderer final : public ContainerRenderer<VBoxContainer>
    {
    public:
        void doLayout(Control& control) const override;
    };
}