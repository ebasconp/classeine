// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "CustomizableRenderer.h"

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

    void CustomizableRenderer::paint(Graphics& gfx,
                              const Region& rgn,
                              const Control& ctrl) const
    {
        if (m_painter)
            m_painter(gfx, rgn, ctrl);
    }
}
