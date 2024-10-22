// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "FlowLayoutContainer.h"

#include "renderers/ContainerRenderer.h"


namespace clsn::ui
{
    FlowLayoutContainer::FlowLayoutContainer()
    : LayoutContainer("flow_container")
    {
    }

    auto FlowLayoutContainer::makeDefaultRenderer() const -> std::unique_ptr<IRenderer>
    {
        return std::make_unique<renderers::ContainerRenderer<FlowLayoutContainer>>();
    }

}