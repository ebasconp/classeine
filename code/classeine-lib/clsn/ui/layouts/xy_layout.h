// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/layouts/layout.h>
#include <clsn/ui/layouts/xy_layout_constraint.h>

#include <clsn/draw/forward.h>

namespace clsn::ui::layouts
{
    class xy_layout final : public layout<xy_layout_constraint>
    {
    public:
        using constraint_type = xy_layout_constraint;

        void do_layout(const draw::region& rgn, layout_element_info_vector&) const override;
    };
}