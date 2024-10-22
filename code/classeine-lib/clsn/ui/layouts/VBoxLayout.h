// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/layouts/Layout.h>

#include <clsn/draw/Forward.h>

#include <variant>

namespace clsn::ui::layouts
{
    class VBoxLayout final : public Layout<std::monostate>
    {
    public:
        using ConstraintType = std::monostate;

        void doLayout(const draw::Region& rgn, LayoutElementInfoVector&) const override;
    };
}