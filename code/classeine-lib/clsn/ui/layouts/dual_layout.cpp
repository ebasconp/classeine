// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "dual_layout.h"

namespace
{
    using namespace clsn::draw;
    using namespace clsn::ui::layouts;

    void layout_vertical(const point& position,
                                      const dimension& size, std::vector<dual_layout::region_and_constraint>& elems)
    {
        const auto count = static_cast<int>(elems.size());
        if (count == 1)
        {
            auto& cc = elems[0];

            auto ch = cc.m_constraint ==
                              dual_layout_constraint::use_all_available_space
                          ? size.get_height()
                          : cc.m_input_region.get_size().get_height();

            cc.m_output_region = {position, {size.get_width(), ch}};
        }

        if (count == 2)
        {
            auto& cc0 = elems[0];
            auto& cc1 = elems[1];

            auto c0h = cc0.m_constraint ==
                               dual_layout_constraint::use_all_available_space
                           ? size.get_height() - cc1.m_input_region.get_height()
                           : cc0.m_input_region.get_height();

            auto c1h = size.get_height() - c0h;

            cc0.m_output_region = {position, {size.get_width(), c0h}};
            cc1.m_output_region = {{position.get_x(), position.get_y() + c0h},
                            {size.get_width(), c1h}};
        }
    }

    void layout_horizontal(const point& position,
                                        const dimension& size,
                                        std::vector<dual_layout::region_and_constraint>& elems)
    {
        const auto count = static_cast<int>(elems.size());
        if (count == 1)
        {
            auto& cc = elems[0];

            auto cw = cc.m_constraint ==
                              dual_layout_constraint::use_all_available_space
                          ? size.get_width()
                          : cc.m_input_region.get_width();

            cc.m_output_region = {position, {cw, size.get_height()}};
        }

        if (count == 2)
        {
            auto& cc0 = elems[0];
            auto& cc1 = elems[1];

            auto c0w = cc0.m_constraint ==
                               dual_layout_constraint::use_all_available_space
                           ? size.get_width() - cc1.m_input_region.get_width()
                           : cc0.m_input_region.get_width();

            auto c1w = size.get_width() - c0w;

            cc0.m_output_region = {position, {c0w, size.get_height()}};
            cc1.m_output_region = {{position.get_x() + c0w, position.get_y()},
                            {c1w, size.get_height()}};
        }
    }
}

namespace clsn::ui::layouts
{
    using namespace clsn::draw;

    dual_layout::dual_layout()
    : m_orientation{dual_layout_orientation::horizontal}
    {
    }

    auto dual_layout::get_orientation() const -> dual_layout_orientation
    {
        return m_orientation;
    }

    void dual_layout::set_orientation(dual_layout_orientation orientation)
    {
        m_orientation = orientation;
    }

    void dual_layout::do_layout(const region& rgn, std::vector<region_and_constraint>& elems) const
    {
        if (elems.empty())
            return;

        const auto& position = rgn.get_position();
        const auto& size = rgn.get_size();

        switch (m_orientation)
        {
            case dual_layout_orientation::horizontal:
                layout_horizontal(position, size, elems);
                break;

            default: layout_vertical(position, size, elems);
        }
    };
}