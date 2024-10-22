// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/Forward.h>
#include <clsn/ui/IRenderer.h>

namespace clsn::ui::renderers
{
    class RadioButtonRenderer : public ui::IRenderer
    {
    public:
        void paint(Graphics& gfx,
                   const draw::Region& rgn,
                   const Control& ctrl) const override;
    };
}