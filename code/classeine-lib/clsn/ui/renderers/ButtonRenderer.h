// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/Forward.h>
#include <clsn/ui/IRenderer.h>

namespace clsn::ui::renderers
{
    class ButtonRenderer : public IRenderer
    {
    public:
        [[nodiscard]] virtual auto paint_as_pressed(const ClickableControl& btn) const -> bool;

        void paint(Graphics& gfx,
                   const clsn::draw::Region& rgn,
                   const Control& ctrl) const override;
    };
}