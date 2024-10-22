// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/renderers/RadioButtonRenderer.h>

#include <clsn/ui/RadioButton.h>
#include <clsn/ui/UIManager.h>

#include <clsn/ui/layouts/DualLayout.h>

#include <clsn/ui/painters/BackgroundPainter.h>
#include <clsn/ui/painters/LabelPainter.h>
#include <clsn/ui/painters/RadioButtonPainter.h>

#include <clsn/draw/Colors.h>
#include <clsn/draw/Region.h>

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

    void RadioButtonRenderer::paint(Graphics& gfx,
                   const Region& rgn,
                   const Control& base_ctrl) const
    {
        const auto& rd_btn = static_cast<const RadioButton&>(base_ctrl);

        const auto sectionName = rd_btn.getDefaultSectionName();

        const auto btn_clr = rd_btn.isPressed()
            ? Color{192, 192, 192}
            : UIManager::get_instance().getColor(sectionName, "controlBackgroundColor");

        using namespace clsn::ui::painters;
        using namespace clsn::ui::layouts;

        BackgroundPainter::paint(gfx, rgn, btn_clr);

        const auto text_size = gfx.getTextSize(rd_btn.getActualFont(), rd_btn.getCaption());
        const auto size = text_size.getHeight();

        DualLayout Layout;

        DualLayout::LayoutElementInfoVector infos;
        infos.emplace_back(draw::Region{0, 0, size, size}, DualLayoutConstraint::use_preferred_size, true);
        infos.emplace_back(draw::Region{0, 0, 0, 0}, DualLayoutConstraint::use_all_available_space, true);

        Layout.doLayout(rgn, infos);

        RadioButtonPainter::paint(gfx, infos[0].getOutputRegion(), rd_btn, size);

        using namespace clsn::ui::painters;
        PaintingInfo info{TextHorizontalAlignment::left, TextVerticalAlignment::middle};

        LabelPainter::paint(gfx, infos[1].getOutputRegion(), rd_btn, info);
    }
}