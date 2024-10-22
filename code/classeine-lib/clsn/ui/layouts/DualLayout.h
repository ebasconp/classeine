// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/layouts/Layout.h>

#include <clsn/draw/Forward.h>

namespace clsn::ui::layouts
{
    enum class DualLayoutOrientation
    {
        horizontal,
        vertical
    };

    enum class DualLayoutConstraint
    {
        use_preferred_size,
        use_all_available_space
    };

    class DualLayout final : public Layout<DualLayoutConstraint>
    {
        DualLayoutOrientation m_orientation;

    public:
        using ConstraintType = DualLayoutConstraint;

        DualLayout();

        [[nodiscard]] auto getOrientation() const -> DualLayoutOrientation;
        void setOrientation(DualLayoutOrientation orientation);

        void doLayout(const draw::Region& rgn, LayoutElementInfoVector&) const override;
    };
}
