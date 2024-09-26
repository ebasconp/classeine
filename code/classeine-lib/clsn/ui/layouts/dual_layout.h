// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "layout_base.h"

#include <clsn/draw/forward.h>

namespace clsn::ui::layouts
{
    enum class dual_layout_orientation
    {
        horizontal,
        vertical
    };

    enum class dual_layout_constraint
    {
        use_preferred_size,
        use_all_available_space
    };

    class dual_layout final : public layout_base<dual_layout_constraint>
    {
        dual_layout_orientation m_orientation;

    public:
        using constraint_type = dual_layout_constraint;

        dual_layout();

        auto get_orientation() const -> dual_layout_orientation;
        void set_orientation(dual_layout_orientation orientation);

        void do_layout(const draw::region& rgn, std::vector<region_and_constraint>&) const override;
    };
}
