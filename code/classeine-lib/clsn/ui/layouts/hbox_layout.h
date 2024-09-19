// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/layouts/layout_base.h>

#include <variant>

namespace clsn::ui::layouts
{
    class hbox_layout final : public layout_base<std::monostate>
    {
    public:
        using constraint_type = std::monostate;

        void layout(const clsn::draw::region& rgn) override;
    };
}