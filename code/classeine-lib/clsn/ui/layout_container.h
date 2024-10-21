// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/constrained_container.h>

#include <clsn/ui/layouts/layout_utils.h>

namespace clsn::ui
{
    template <typename Layout>
    class layout_container : public constrained_container<typename Layout::constraint_type>
    {
        Layout m_layout;

    public:
        using constraint_type = typename Layout::constraint_type;

        explicit layout_container(std::string_view sectionName)
        : constrained_container<constraint_type>{sectionName}
        {
        }

        ~layout_container() override = default;

        auto get_layout() -> Layout&
        {
            return m_layout;
        }

        auto get_layout() const -> const Layout&
        {
            return m_layout;
        }

        void do_layout() override
        {
            if (this->get_visible_count() == 0)
                return;

            auto infos = layouts::layout_utils::to_layout_info(*this);

            m_layout.do_layout(this->get_actual_bounds(), infos);

            int count = this->get_count();
            for (int i = 0, j = 0; i < count; i++)
            {
                auto& ctrl = (*this)[i];
                if (!ctrl.isVisible())
                    continue;

                auto& rgn = infos[i].get_output_region();

                ctrl.setActualPosition(rgn.getPosition());
                ctrl.setActualSize(rgn.getSize());

                j++;
            }
        }
    };
}
