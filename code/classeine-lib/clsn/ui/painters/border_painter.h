// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "clsn/ui/graphics.h"

#include "clsn/draw/forward.h"

namespace clsn::ui::painters::border_painter
{
    void paint_flat_border(graphics& gfx,
                   const clsn::draw::region& rgn,
                   const clsn::draw::color& c,
                   int depth);
}