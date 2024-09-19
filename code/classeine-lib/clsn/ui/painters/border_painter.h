// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/graphics.h>

#include <clsn/draw/forward.h>

#include <clsn/core/non_instantiable.h>

namespace clsn::ui::painters
{
    class border_painter final : public core::non_instantiable
    {
    public:
        static void paint_flat_border(graphics& gfx,
                     const clsn::draw::region& rgn,
                     const clsn::draw::color& c,
                     int depth);
    };
}