// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "clsn/ui/renderers/label_renderer.h"

namespace clsn::ui::renderers
{
    class check_box_renderer : public renderer_base
    {
    public:
        void paint(graphics& graphics,
                   const clsn::draw::Region& Region,
                   const control& baseControl) const override;
    };
}