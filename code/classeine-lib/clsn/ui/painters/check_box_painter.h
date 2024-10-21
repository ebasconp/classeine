// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/forward.h>
#include <clsn/ui/graphics.h>

#include <clsn/draw/forward.h>

#include <clsn/core/NonInstantiable.h>

namespace clsn::ui::painters
{
    class check_box_painter final : public core::NonInstantiable
    {
    public:
        static void paint_check_box(graphics& gfx, const clsn::draw::region& rgn, const check_box& cb, int size);
    };
}