// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/forward.h>
#include <clsn/ui/renderer_base.h>

namespace clsn::ui::renderers
{
    class radio_button_renderer : public ui::renderer_base
    {
    public:
        void paint(graphics& gfx,
                   const draw::region& rgn,
                   const control& ctrl) const override;
    };
}