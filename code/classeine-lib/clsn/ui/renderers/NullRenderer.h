// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/IRenderer.h>

namespace clsn::ui::renderers
{
    class NullRenderer : public IRenderer
    {
    public:
        void paint(Graphics&, const draw::Region&, const Control&) const override
        {
            // Nothing to do here
        }
    };
}