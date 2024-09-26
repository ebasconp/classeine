// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/layouts/layout.h>

#include <clsn/draw/forward.h>

#include <variant>

namespace clsn::ui::layouts
{
    class flow_layout final : public layout<std::monostate>
    {
    public:
        using constraint_type = std::monostate;

        void do_layout(const draw::region& rgn, layout_element_info_vector&) const override;
    };
}