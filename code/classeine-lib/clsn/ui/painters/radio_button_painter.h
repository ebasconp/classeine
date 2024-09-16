// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "clsn/ui/graphics.h"

#include "clsn/draw/forward.h"

namespace clsn::ui
{
    class radio_button;
}

namespace clsn::ui::painters::radio_button_painter
{
    void paint_radio_button(graphics& gfx,
                            const clsn::draw::region& rgn,
                            const radio_button& rb,
                            int size);
}