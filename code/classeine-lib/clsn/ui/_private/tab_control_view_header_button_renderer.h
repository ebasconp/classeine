// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/renderers/toggle_button_renderer.h>

namespace clsn::ui::_private
{
    class tab_control_view_header_button_renderer : public renderers::toggle_button_renderer
    {
    public:
        void paint(graphics& gfx,
           const clsn::draw::region& rgn,
           const control& ctrl) const override;
    };
}