// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/layouts/vbox_layout.h>

#include <algorithm>

namespace clsn::ui::layouts
{
    using namespace clsn::draw;

    void vbox_layout::do_layout(const draw::Region& rgn, layout_element_info_vector& elems) const
    {
        const auto count = static_cast<int>(elems.size());

        const auto visible_count = static_cast<int>(
            std::ranges::count_if(
                elems,
                [](auto& e) { return e.isVisible(); }));

        if (visible_count == 0)
            return;

        const auto& actual_size = rgn.getSize();
        const auto width = actual_size.getWidth();
        const auto height = actual_size.getHeight() / visible_count;

        const auto position = rgn.getPosition();

        int last_y = 0;
        for (int i = 0; i < count; i++)
        {
            if (!elems[i].isVisible())
                continue;

            const auto actual_height = i < count - 1 ? height : actual_size.getHeight() - last_y;

            elems[i].set_output_region({ {position.getX(), last_y + position.getY()}, {width, actual_height} });

            last_y += height;
        }
    };
}