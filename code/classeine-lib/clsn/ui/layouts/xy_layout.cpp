// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/layouts/xy_layout.h>

namespace clsn::ui::layouts
{
    using namespace clsn::draw;

    void xy_layout::do_layout(const draw::region& rgn, std::vector<region_and_constraint>& elems) const
    {
        const auto count = static_cast<int>(elems.size());
        if (count == 0)
            return;

        const auto& position = rgn.get_position();

        for (int i = 0; i < count; i++)
        {
            auto& elem = elems[i];
            if (!elem.m_visible)
                continue;

            elem.m_output_region = { {position.get_x() + elem.m_constraint.get_position().get_x(), position.get_y() + elem.m_constraint.get_position().get_y()},
                                elem.m_input_region.get_size() };
        }
    };
}