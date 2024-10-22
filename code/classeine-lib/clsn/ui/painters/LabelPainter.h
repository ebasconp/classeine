// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/core/NonInstantiable.h>

#include <clsn/ui/Forward.h>
#include <clsn/ui/Graphics.h>

#include <clsn/draw/Forward.h>

namespace clsn::ui::painters
{
    struct PaintingInfo final
    {
        clsn::draw::TextHorizontalAlignment horizontal_alignment;
        clsn::draw::TextVerticalAlignment vertical_alignment;
    };

    class LabelPainter final : public core::NonInstantiable
    {
    public:
        static void paint(Graphics& gfx,
                     const draw::Region& rgn,
                     const CaptionableControl& ctrl,
                     const PaintingInfo& info);
    };
}