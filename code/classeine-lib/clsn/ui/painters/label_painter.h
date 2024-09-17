// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/forward.h>
#include <clsn/ui/graphics.h>

#include <clsn/draw/forward.h>

namespace clsn::ui::painters::label_painter
{
    struct painting_info final
    {
        clsn::draw::text_horizontal_alignment horizontal_alignment;
        clsn::draw::text_vertical_alignment vertical_alignment;
    };

    void paint_label(graphics& gfx,
                     const draw::region& rgn,
                     const captionable_control& ctrl,
                     const painting_info& info);
}