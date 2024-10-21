// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/core/NonInstantiable.h>

#include <clsn/ui/forward.h>
#include <clsn/ui/graphics.h>

#include <clsn/draw/Forward.h>

namespace clsn::ui::painters
{
    struct painting_info final
    {
        clsn::draw::TextHorizontalAlignment horizontal_alignment;
        clsn::draw::TextVerticalAlignment vertical_alignment;
    };

    class label_painter final : public core::NonInstantiable
    {
    public:
        static void paint_label(graphics& gfx,
                     const draw::Region& rgn,
                     const captionable_control& ctrl,
                     const painting_info& info);
    };
}