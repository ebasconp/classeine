// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "clsn/ui/renderer_base.h"

namespace clsn::ui
{
  class clickable_control;
}

namespace clsn::ui::renderers
{
    using namespace clsn::draw;
    using namespace clsn::ui;

    class button_renderer : public renderer_base
    {
    public:
        [[nodiscard]] virtual auto paint_as_pressed(const clickable_control& btn) const -> bool;

        void paint(graphics& gfx,
                   const region& rgn,
                   const control& ctrl) const override;
    };
}