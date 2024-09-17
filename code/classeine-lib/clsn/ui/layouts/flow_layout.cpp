// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "flow_layout.h"

namespace clsn::ui::layouts
{
    using namespace clsn::draw;

    void flow_layout::layout(const region& rgn)
    {
        const auto count = get_count();
        if (count == 0)
            return;

        const auto& size = rgn.get_size();
        const auto& position = rgn.get_position();

        const auto width = size.get_width();

        int currentx = position.get_x();
        int currenty = position.get_y();

        int maxx = currentx + width;
        int maxy = 0;

        for (int i = 0; i < count; i++)
        {
            auto& r = get_element_at(i).m_region;

            auto control_width = r.get_size().get_width();

            if (currentx + control_width < maxx)
            {
                const auto& preferred_size = r.get_size();
                if (maxy < preferred_size.get_height())
                    maxy = preferred_size.get_height();

                r = { {currentx, currenty}, preferred_size };
            }
            else
            {
                currentx = position.get_x();
                currenty += maxy;

                const auto& preferred_size = r.get_size();
                if (maxy < preferred_size.get_height())
                    maxy = preferred_size.get_height();

                r = { {currentx, currenty}, preferred_size };
            }

            currentx += control_width;
        }
    };
}