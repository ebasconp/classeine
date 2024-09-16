// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "clsn/ui/renderer_base.h"

namespace clsn::ui::renderers
{
    class label_renderer : public renderer_base
    {
    public:
        void paint(graphics& graphics,
                   const clsn::draw::region& region,
                   const control& control) const override;
    };
}