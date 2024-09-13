// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "clsn/ui/renderer_base.h"

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

    class dynamic_pane_renderer : public renderer_base
    {
    public:
        void paint(graphics& gfx,
                   const region& rgn,
                   const control& ctrl) const override;
    };
}