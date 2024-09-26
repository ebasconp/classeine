// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/layouts/vbox_layout.h>

#include <algorithm>

namespace clsn::ui::layouts
{
    using namespace clsn::draw;

    void vbox_layout::do_layout(const draw::region& rgn, layout_element_info_vector& elems) const
    {
        const auto count = static_cast<int>(elems.size());

        const auto visible_count = static_cast<int>(
            std::ranges::count_if(
                elems,
                [](auto& e) { return e.m_visible; }));

        if (visible_count == 0)
            return;

        const auto& actual_size = rgn.get_size();
        const auto width = actual_size.get_width();
        const auto height = actual_size.get_height() / visible_count;

        const auto position = rgn.get_position();

        int last_y = 0;
        for (int i = 0; i < count; i++)
        {
            if (!elems[i].m_visible)
                continue;

            const auto actual_height = i < count - 1 ? height : actual_size.get_height() - last_y;

            elems[i].m_output_region = { {position.get_x(), last_y + position.get_y()}, {width, actual_height} };

            last_y += height;
        }
    };
}