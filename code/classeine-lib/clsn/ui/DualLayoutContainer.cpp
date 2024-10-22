// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "DualLayoutContainer.h"

#include "renderers/ContainerRenderer.h"

#include "clsn/core/System.h"

namespace clsn::ui
{
    using namespace clsn::ui::layouts;

    DualLayoutContainer::DualLayoutContainer()
    : LayoutContainer<layouts::DualLayout>{"DualLayoutContainer"}
    {
    }

    auto DualLayoutContainer::getOrientation() const -> DualLayoutOrientation
    {
        return this->getLayout().getOrientation();
    }

    void DualLayoutContainer::setOrientation(DualLayoutOrientation orientation)
    {
        this->getLayout().setOrientation(orientation);
    }

    void DualLayoutContainer::checkIfValidBeforeAdding(const DualLayoutConstraint& constraint) const
    {
        if (getCount() == 2)
            core::System::panic("Dual Container can only contain two elements");

        if (getCount() == 1 && constraint == getElementAt(0).getConstraint())
            core::System::panic("Both controls must have different constraints");
    }


    auto DualLayoutContainer::makeDefaultRenderer() const -> std::unique_ptr<IRenderer>
    {
        return std::make_unique<renderers::ContainerRenderer<DualLayoutContainer>>();
    }
}