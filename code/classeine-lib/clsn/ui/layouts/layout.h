// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "clsn/draw/region.h"

#include <vector>

namespace clsn::ui::layouts
{
    template <typename Constraint>
    class layout
    {
    public:
        struct layout_element_info
        {
            layout_element_info(const draw::region& input_region, const Constraint& constraint, bool visible)
            : m_input_region{input_region}
            , m_output_region{0, 0, 0, 0}
            , m_constraint{constraint}
            , m_visible{visible}
            {
            }

            const draw::region m_input_region;
            draw::region m_output_region;
            Constraint m_constraint;
            bool m_visible;
        };

        using layout_element_info_vector = std::vector<layout_element_info>;

        virtual ~layout() = default;

        virtual void do_layout(const draw::region& rgn, layout_element_info_vector&) const = 0;
    };
}