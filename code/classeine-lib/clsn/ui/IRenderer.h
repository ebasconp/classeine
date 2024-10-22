// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/draw/Forward.h>

#include <clsn/ui/Forward.h>
#include <clsn/ui/Graphics.h>

namespace clsn::ui
{
    class IRenderer : public clsn::core::Entity
    {
    public:
        ~IRenderer() override = default;

        virtual void paint(Graphics& gfx,
                           const clsn::draw::Region& rgn,
                           const clsn::ui::Control& ctrl) const = 0;
    };
}