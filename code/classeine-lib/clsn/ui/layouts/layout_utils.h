// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/core/non_instantiable.h>

#include <algorithm>

namespace clsn::ui
{
    template <typename LayoutType>
    class layout_container;
}

namespace clsn::ui::layouts
{
    class layout_utils : public clsn::core::non_instantiable
    {
    public:
        template <typename LayoutType>
        static auto to_layout_info(layout_container<LayoutType>& container)
                    -> typename LayoutType::layout_element_info_vector
        {
            typename LayoutType::layout_element_info_vector infos;

            auto elems = container.get_elements();

            std::transform(
                    elems.begin(), elems.end(),
                    std::back_inserter(infos), [](auto& e)
                    {
                        auto& c = *e.get_control_ptr();

                        return typename LayoutType::layout_element_info
                        {
                            { c.get_actual_position(), c.get_actual_preferred_size() },
                            e.get_constraint(),
                            c.is_visible()
                        };
                    });

            return infos;
        }
    };
}