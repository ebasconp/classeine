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
    class radio_button_painter final : public core::NonInstantiable
    {
    public:
        static void paint_radio_button(graphics& gfx,
                          const clsn::draw::region& rgn,
                          const radio_button& rb,
                          int size);
    };
}