// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/layouts/xy_layout.h>

namespace clsn::ui::layouts
{
    using namespace clsn::draw;

    void xy_layout::do_layout(const draw::Region& rgn, layout_element_info_vector& elems) const
    {
        const auto count = static_cast<int>(elems.size());
        if (count == 0)
            return;

        const auto& position = rgn.getPosition();

        for (int i = 0; i < count; i++)
        {
            auto& elem = elems[i];
            if (!elem.isVisible())
                continue;

            elem.set_output_region({ {position.getX() + elem.get_constraint().getPosition().getX(), position.getY() + elem.get_constraint().getPosition().getY()},
                                elem.get_input_region().getSize() });
        }
    };
}