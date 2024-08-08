#pragma once

#include "clsn/ui/vbox_container.h"

#include "clsn/ui/renderers/ContainerRenderer.h"

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

    class VBoxContainerRenderer final : public ContainerRenderer<vbox_container>
    {
    public:
    };
}