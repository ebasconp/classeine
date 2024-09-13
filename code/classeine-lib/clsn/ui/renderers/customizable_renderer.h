// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "clsn/ui/renderer_base.h"

#include <functional>

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

    class customizable_renderer : public renderer_base
    {
        std::function<void(graphics&, const region&, const control&)> m_painter;

    public:
        template <typename Proc>
        customizable_renderer(Proc proc)
        {
            m_painter = std::move(proc);
        }

        void paint(
            graphics& gfx, const region& rgn, const control& ctrl) const override;
    };
}