// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/renderers/customizable_renderer.h>

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

    void customizable_renderer::paint(graphics& gfx,
                              const region& rgn,
                              const control& ctrl) const
    {
        if (m_painter)
            m_painter(gfx, rgn, ctrl);
    }
}
