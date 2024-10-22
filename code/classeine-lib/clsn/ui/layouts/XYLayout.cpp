// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/layouts/XYLayout.h>

namespace clsn::ui::layouts
{
    using namespace clsn::draw;

    void XYLayout::doLayout(const draw::Region& rgn, LayoutElementInfoVector& elems) const
    {
        const auto count = static_cast<int>(elems.size());
        if (count == 0)
            return;

        const auto& position = rgn.getPosition();

        for (int i = 0; i < count; i++)
        {
            auto& elem = elems[i];
            if (!elem.isVisible())
                continue;

            elem.setOutputRegion({ {position.getX() + elem.getConstraint().getPosition().getX(), position.getY() + elem.getConstraint().getPosition().getY()},
                                elem.getInputRegion().getSize() });
        }
    };
}