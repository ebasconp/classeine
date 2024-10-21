// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/layouts/dual_layout.h>

namespace
{
    using namespace clsn::draw;
    using namespace clsn::ui::layouts;

    void layout_vertical(const Point& position,
                                      const Dimension& size, dual_layout::layout_element_info_vector& elems)
    {
        const auto count = static_cast<int>(elems.size());
        if (count == 1)
        {
            auto& cc = elems[0];

            auto ch = cc.get_constraint() ==
                              dual_layout_constraint::use_all_available_space
                          ? size.getHeight()
                          : cc.get_input_region().getSize().getHeight();

            cc.set_output_region({position, {size.getWidth(), ch}});
        }

        if (count == 2)
        {
            auto& cc0 = elems[0];
            auto& cc1 = elems[1];

            auto c0h = cc0.get_constraint() ==
                               dual_layout_constraint::use_all_available_space
                           ? size.getHeight() - cc1.get_input_region().getHeight()
                           : cc0.get_input_region().getHeight();

            auto c1h = size.getHeight() - c0h;

            cc0.set_output_region({position, {size.getWidth(), c0h}});
            cc1.set_output_region({{position.getX(), position.getY() + c0h},
                            {size.getWidth(), c1h}});
        }
    }

    void layout_horizontal(const Point& position,
                                        const Dimension& size,
                                        dual_layout::layout_element_info_vector& elems)
    {
        const auto count = static_cast<int>(elems.size());
        if (count == 1)
        {
            auto& cc = elems[0];

            auto cw = cc.get_constraint() ==
                              dual_layout_constraint::use_all_available_space
                          ? size.getWidth()
                          : cc.get_input_region().getWidth();

            cc.set_output_region({position, {cw, size.getHeight()}});
        }

        if (count == 2)
        {
            auto& cc0 = elems[0];
            auto& cc1 = elems[1];

            auto c0w = cc0.get_constraint() ==
                               dual_layout_constraint::use_all_available_space
                           ? size.getWidth() - cc1.get_input_region().getWidth()
                           : cc0.get_input_region().getWidth();

            auto c1w = size.getWidth() - c0w;

            cc0.set_output_region({position, {c0w, size.getHeight()}});
            cc1.set_output_region({{position.getX() + c0w, position.getY()},
                            {c1w, size.getHeight()}});
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

    void dual_layout::do_layout(const Region& rgn, layout_element_info_vector& elems) const
    {
        if (elems.empty())
            return;

        const auto& position = rgn.getPosition();
        const auto& size = rgn.getSize();

        switch (m_orientation)
        {
            case dual_layout_orientation::horizontal:
                layout_horizontal(position, size, elems);
                break;

            default: layout_vertical(position, size, elems);
        }
    };
}