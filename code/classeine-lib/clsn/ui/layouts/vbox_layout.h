// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "layout_base.h"

#include <clsn/draw/forward.h>

#include <variant>

namespace clsn::ui::layouts
{
    class vbox_layout final : public layout_base<std::monostate>
    {
    public:
        using constraint_type = std::monostate;

        void do_layout(const draw::region& rgn, std::vector<region_and_constraint>&) const override;
    };
}