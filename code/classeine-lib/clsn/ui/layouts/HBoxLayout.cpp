// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/layouts/HBoxLayout.h>

#include <algorithm>

namespace clsn::ui::layouts
{
    using namespace clsn::draw;

    void HBoxLayout::doLayout(const draw::Region& rgn, LayoutElementInfoVector& elems) const
    {
        const auto count = static_cast<int>(elems.size());
        const auto visible_count = static_cast<int>(
            std::ranges::count_if(elems, [](auto& e) { return e.isVisible(); }));

        if (visible_count == 0)
            return;

        const auto& actual_size = rgn.getSize();
        const auto width = actual_size.getWidth() / visible_count;
        const auto height = actual_size.getHeight();

        const auto position = rgn.getPosition();

        int last_x = 0;
        for (int i = 0; i < count; i++)
        {
            const auto actual_width = i < count - 1 ? width : actual_size.getWidth() - last_x;

            elems[i].setOutputRegion({ {last_x + position.getX(), position.getY()}, {actual_width, height} });

            last_x += width;
        }
    };
}