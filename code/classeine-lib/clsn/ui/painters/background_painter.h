// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "clsn/ui/graphics.h"

#include "clsn/draw/forward.h"

namespace clsn::ui::painters::background_painter
{
    using namespace clsn::draw;

    void paint_background(graphics& gfx, const region& rgn, const color& clr);
}