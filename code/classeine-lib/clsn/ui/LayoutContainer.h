// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/ConstrainedContainer.h>

#include <clsn/ui/layouts/LayoutUtils.h>

namespace clsn::ui
{
    template <typename Layout>
    class LayoutContainer : public ConstrainedContainer<typename Layout::ConstraintType>
    {
        Layout m_layout;

    public:
        using ConstraintType = typename Layout::ConstraintType;

        explicit LayoutContainer(std::string_view sectionName)
        : ConstrainedContainer<ConstraintType>{sectionName}
        {
        }

        ~LayoutContainer() override = default;

        auto getLayout() -> Layout&
        {
            return m_layout;
        }

        auto getLayout() const -> const Layout&
        {
            return m_layout;
        }

        void doLayout() override
        {
            if (this->getVisibleCount() == 0)
                return;

            auto infos = layouts::LayoutUtils::to_layout_info(*this);

            m_layout.doLayout(this->getActualBounds(), infos);

            int count = this->getCount();
            for (int i = 0, j = 0; i < count; i++)
            {
                auto& ctrl = (*this)[i];
                if (!ctrl.isVisible())
                    continue;

                auto& rgn = infos[i].getOutputRegion();

                ctrl.setActualPosition(rgn.getPosition());
                ctrl.setActualSize(rgn.getSize());

                j++;
            }
        }
    };
}
