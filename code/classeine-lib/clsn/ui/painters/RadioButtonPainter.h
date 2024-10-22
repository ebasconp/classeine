// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/Forward.h>
#include <clsn/ui/Graphics.h>

#include <clsn/draw/Forward.h>

#include <clsn/core/NonInstantiable.h>

namespace clsn::ui::painters
{
    class RadioButtonPainter final : public core::NonInstantiable
    {
    public:
        static void paint(Graphics& gfx,
                          const clsn::draw::Region& rgn,
                          const RadioButton& rb,
                          int size);
    };
}