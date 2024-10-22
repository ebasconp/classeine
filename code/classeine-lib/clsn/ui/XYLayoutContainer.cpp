// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/XYLayoutContainer.h>

#include <clsn/ui/renderers/ContainerRenderer.h>

namespace clsn::ui
{
    XYLayoutContainer::XYLayoutContainer()
    : LayoutContainer("XYLayoutContainer")
    {
    }

    auto XYLayoutContainer::makeDefaultRenderer() const -> std::unique_ptr<IRenderer>
    {
        return std::make_unique<renderers::ContainerRenderer<XYLayoutContainer>>();
    }
}