// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/renderers/EmptyControlRenderer.h>

#include <clsn/ui/EmptyControl.h>
#include <clsn/ui/UIManager.h>

#include <clsn/ui/painters/BackgroundPainter.h>

namespace clsn::ui::renderers
{
    using namespace clsn::draw;
    using namespace clsn::ui;

    void EmptyControlRenderer::paint(Graphics& gfx,
                              const Region& rgn,
                              const Control& ctrl) const
    {
        const auto& bc = UIManager::get_instance()
                        .getColor(ctrl.getDefaultSectionName(), "containerBackgroundColor");

        painters::BackgroundPainter::paint(gfx, rgn, bc);
    }
}
