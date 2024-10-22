// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/IRenderer.h>

#include <functional>

namespace clsn::ui::renderers
{
    class CustomizableRenderer : public IRenderer
    {
        std::function<void(Graphics&, const clsn::draw::Region&, const Control&)> m_painter;

    public:
        template <typename Proc>
        CustomizableRenderer(Proc proc)
        {
            m_painter = std::move(proc);
        }

        void paint(
            Graphics& gfx, const clsn::draw::Region& rgn, const Control& ctrl) const override;
    };
}