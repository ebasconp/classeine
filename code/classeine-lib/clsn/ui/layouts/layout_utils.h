// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/core/non_instantiable.h>

#include <clsn/ui/layouts/layout_base.h>

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
        {
            std::vector<typename LayoutType::region_and_constraint> infos;

            auto elems = container.get_elements();

            std::transform(
                    elems.begin(), elems.end(),
                    std::back_inserter(infos), [](auto& e)
                    {
                        auto& c = *e.m_control;

                        return typename LayoutType::region_and_constraint
                        {
                            { c.get_actual_position(), c.get_actual_preferred_size() },
                            e.m_constraint,
                            c.is_visible()
                        };
                    });

            return infos;
        }
    };
}