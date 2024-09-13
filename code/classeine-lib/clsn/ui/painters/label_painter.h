// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "clsn/ui/graphics.h"

#include "clsn/draw/forward.h"
#include "clsn/draw/text_horizontal_alignment.h"
#include "clsn/draw/text_vertical_alignment.h"

namespace clsn::ui
{
    class control;
}

namespace clsn::ui::painters
{

}

namespace clsn::ui::painters::label_painter
{
    using namespace clsn::draw;

    struct painting_info final
    {
        text_horizontal_alignment horizontal_alignment;
        text_vertical_alignment vertical_alignment;
    };

    using namespace clsn::draw;

    void paint_label(graphics& gfx,
                     const region& rgn,
                     const control& ctrl,
                     const painting_info& info);
}