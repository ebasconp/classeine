// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/renderers/LabelRenderer.h>

#include <clsn/ui/Label.h>
#include <clsn/ui/UIManager.h>

#include <clsn/ui/painters/BackgroundPainter.h>
#include <clsn/ui/painters/LabelPainter.h>

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

    void LabelRenderer::paint(Graphics& gfx,
                              const Region& rgn,
                              const Control& ctrl) const
    {
        const auto sectionName = ctrl.getDefaultSectionName();

        const auto& _label = static_cast<const Label&>(ctrl);

        const auto bc = _label.getBackgroundColor().has_value()
                ? _label.getBackgroundColor().value()
                : UIManager::get_instance().getColor(sectionName, "containerBackgroundColor");

        painters::BackgroundPainter::paint(gfx, rgn, bc);

        using namespace clsn::ui::painters;
        PaintingInfo info{_label.getHorizontalAlignment(),
                           _label.getVerticalAlignment()};

        LabelPainter::paint(gfx, rgn, _label, info);
    }
}
