// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "HBoxLayoutContainer.h"

#include "renderers/ContainerRenderer.h"

namespace clsn::ui
{
    HBoxLayoutContainer::HBoxLayoutContainer()
    : LayoutContainer("HBoxLayoutContainer")
    {
    }

    auto HBoxLayoutContainer::makeDefaultRenderer() const -> std::unique_ptr<IRenderer>
    {
        return std::make_unique<renderers::ContainerRenderer<HBoxLayoutContainer>>();
    }
}