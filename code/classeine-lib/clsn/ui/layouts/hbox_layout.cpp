// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/layouts/hbox_layout.h>

#include <algorithm>

namespace clsn::ui::layouts
{
    using namespace clsn::draw;

    void hbox_layout::do_layout(const draw::region& rgn, layout_element_info_vector& elems) const
    {
        const auto count = static_cast<int>(elems.size());
        const auto visible_count = static_cast<int>(
            std::ranges::count_if(elems, [](auto& e) { return e.m_visible; }));

        if (visible_count == 0)
            return;

        const auto& actual_size = rgn.get_size();
        const auto width = actual_size.get_width() / visible_count;
        const auto height = actual_size.get_height();

        const auto position = rgn.get_position();

        int last_x = 0;
        for (int i = 0; i < count; i++)
        {
            const auto actual_width = i < count - 1 ? width : actual_size.get_width() - last_x;

            elems[i].m_output_region = { {last_x + position.get_x(), position.get_y()}, {actual_width, height} };

            last_x += width;
        }
    };
}