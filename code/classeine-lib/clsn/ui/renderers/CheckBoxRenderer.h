// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/IRenderer.h>

namespace clsn::ui::renderers
{
    class CheckBoxRenderer : public IRenderer
    {
    public:
        void paint(Graphics& Graphics,
                   const clsn::draw::Region& Region,
                   const Control& baseControl) const override;
    };
}