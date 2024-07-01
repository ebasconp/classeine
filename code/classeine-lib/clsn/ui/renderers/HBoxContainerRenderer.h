#pragma once

#include "clsn/ui/HBoxContainer.h"

#include "clsn/ui/renderers/ContainerRenderer.h"

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

    class HBoxContainerRenderer final : public ContainerRenderer<HBoxContainer>
    {
    public:
        void doLayout(Control& baseControl) const override;
    };
}