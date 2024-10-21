// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/graphics.h>

#include <clsn/draw/Forward.h>

#include <clsn/core/NonInstantiable.h>

namespace clsn::ui::painters
{
    class border_painter final : public core::NonInstantiable
    {
    public:
        static void paint_flat_border(graphics& gfx,
                     const clsn::draw::Region& rgn,
                     const clsn::draw::Color& c,
                     int depth);
    };
}