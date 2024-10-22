// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/LayoutContainer.h>

#include <clsn/ui/layouts/DualLayout.h>

namespace clsn::ui
{
    class DualLayoutContainer : public LayoutContainer<layouts::DualLayout>
    {
        layouts::DualLayoutOrientation m_orientation = layouts::DualLayoutOrientation::horizontal;

    public:
        DualLayoutContainer();

        auto getOrientation() const -> layouts::DualLayoutOrientation;
        void setOrientation(layouts::DualLayoutOrientation orientation);

    protected:
        void checkIfValidBeforeAdding(const layouts::DualLayoutConstraint& fill) const override;

        auto makeDefaultRenderer() const -> std::unique_ptr<IRenderer> override;
    };
}