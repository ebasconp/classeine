// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/layouts/flow_layout.h>

namespace clsn::ui::layouts
{
    using namespace clsn::draw;

    void flow_layout::do_layout(const draw::Region& rgn, layout_element_info_vector& elems) const
    {
        const auto count = static_cast<int>(elems.size());
        if (count == 0)
            return;

        const auto& size = rgn.getSize();
        const auto& position = rgn.getPosition();

        const auto width = size.getWidth();

        int currentx = position.getX();
        int currenty = position.getY();

        const int maxx = currentx + width;
        int maxy = 0;

        for (auto& e : elems)
        {
            if (!e.isVisible())
                continue;

            auto& r = e.get_input_region();

            const auto control_width = r.getSize().getWidth();

            if (currentx + control_width < maxx)
            {
                const auto& preferred_size = r.getSize();
                if (maxy < preferred_size.getHeight())
                    maxy = preferred_size.getHeight();

                e.set_output_region({ {currentx, currenty}, preferred_size });
            }
            else
            {
                currentx = position.getX();
                currenty += maxy;

                const auto& preferred_size = r.getSize();
                if (maxy < preferred_size.getHeight())
                    maxy = preferred_size.getHeight();

                e.set_output_region({ {currentx, currenty}, preferred_size });
            }

            currentx += control_width;
        }
    };
}