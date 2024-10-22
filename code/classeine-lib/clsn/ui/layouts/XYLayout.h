// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/layouts/Layout.h>
#include <clsn/ui/layouts/XYLayoutConstraint.h>

#include <clsn/draw/Forward.h>

namespace clsn::ui::layouts
{
    class XYLayout final : public Layout<XYLayoutConstraint>
    {
    public:
        using ConstraintType = XYLayoutConstraint;

        void doLayout(const draw::Region& rgn, LayoutElementInfoVector&) const override;
    };
}