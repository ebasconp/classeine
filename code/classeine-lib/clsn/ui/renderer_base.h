// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/draw/forward.h>

#include <clsn/ui/forward.h>
#include <clsn/ui/graphics.h>

namespace clsn::ui
{
    class renderer_base : public clsn::core::entity
    {
    public:
        ~renderer_base() override = default;

        virtual void paint(graphics& gfx,
                           const clsn::draw::region& rgn,
                           const clsn::ui::control& ctrl) const = 0;
    };
}