// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/layouts/DualLayout.h>

namespace
{
    using namespace clsn::draw;
    using namespace clsn::ui::layouts;

    void layout_vertical(const Point& position,
                                      const Dimension& size, DualLayout::LayoutElementInfoVector& elems)
    {
        const auto count = static_cast<int>(elems.size());
        if (count == 1)
        {
            auto& cc = elems[0];

            auto ch = cc.getConstraint() ==
                              DualLayoutConstraint::use_all_available_space
                          ? size.getHeight()
                          : cc.getInputRegion().getSize().getHeight();

            cc.setOutputRegion({position, {size.getWidth(), ch}});
        }

        if (count == 2)
        {
            auto& cc0 = elems[0];
            auto& cc1 = elems[1];

            auto c0h = cc0.getConstraint() ==
                               DualLayoutConstraint::use_all_available_space
                           ? size.getHeight() - cc1.getInputRegion().getHeight()
                           : cc0.getInputRegion().getHeight();

            auto c1h = size.getHeight() - c0h;

            cc0.setOutputRegion({position, {size.getWidth(), c0h}});
            cc1.setOutputRegion({{position.getX(), position.getY() + c0h},
                            {size.getWidth(), c1h}});
        }
    }

    void layout_horizontal(const Point& position,
                                        const Dimension& size,
                                        DualLayout::LayoutElementInfoVector& elems)
    {
        const auto count = static_cast<int>(elems.size());
        if (count == 1)
        {
            auto& cc = elems[0];

            auto cw = cc.getConstraint() ==
                              DualLayoutConstraint::use_all_available_space
                          ? size.getWidth()
                          : cc.getInputRegion().getWidth();

            cc.setOutputRegion({position, {cw, size.getHeight()}});
        }

        if (count == 2)
        {
            auto& cc0 = elems[0];
            auto& cc1 = elems[1];

            auto c0w = cc0.getConstraint() ==
                               DualLayoutConstraint::use_all_available_space
                           ? size.getWidth() - cc1.getInputRegion().getWidth()
                           : cc0.getInputRegion().getWidth();

            auto c1w = size.getWidth() - c0w;

            cc0.setOutputRegion({position, {c0w, size.getHeight()}});
            cc1.setOutputRegion({{position.getX() + c0w, position.getY()},
                            {c1w, size.getHeight()}});
        }
    }
}

namespace clsn::ui::layouts
{
    using namespace clsn::draw;

    DualLayout::DualLayout()
    : m_orientation{DualLayoutOrientation::horizontal}
    {
    }

    auto DualLayout::getOrientation() const -> DualLayoutOrientation
    {
        return m_orientation;
    }

    void DualLayout::setOrientation(DualLayoutOrientation orientation)
    {
        m_orientation = orientation;
    }

    void DualLayout::doLayout(const Region& rgn, LayoutElementInfoVector& elems) const
    {
        if (elems.empty())
            return;

        const auto& position = rgn.getPosition();
        const auto& size = rgn.getSize();

        switch (m_orientation)
        {
            case DualLayoutOrientation::horizontal:
                layout_horizontal(position, size, elems);
                break;

            default: layout_vertical(position, size, elems);
        }
    };
}