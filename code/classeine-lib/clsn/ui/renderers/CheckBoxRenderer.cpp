// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "CheckBoxRenderer.h"

#include "clsn/ui/CheckBox.h"
#include "clsn/ui/UIManager.h"

#include "clsn/ui/layouts/DualLayout.h"

#include "clsn/ui/painters/BackgroundPainter.h"
#include "clsn/ui/painters/CheckBoxPainter.h"
#include "clsn/ui/painters/LabelPainter.h"

#include "clsn/draw/Region.h"

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

    void CheckBoxRenderer::paint(Graphics& gfx,
                   const Region& rgn,
                   const Control& ctrl) const
    {
        const auto& chk_box = static_cast<const CheckBox&>(ctrl);
        const auto sectionName = chk_box.getDefaultSectionName();

        const auto btn_clr = chk_box.isPressed()
            ? Color{192, 192, 192}
            : UIManager::get_instance().getColor(sectionName, "controlBackgroundColor");

        using namespace clsn::ui::painters;

        BackgroundPainter::paint(gfx, rgn, btn_clr);

        const auto text_size = gfx.getTextSize(chk_box.getActualFont(), chk_box.getCaption());

        const auto size = text_size.getHeight();

        using namespace clsn::ui::layouts;
        DualLayout Layout;

        DualLayout::LayoutElementInfoVector infos;

        infos.emplace_back(draw::Region{0, 0, size, size}, DualLayoutConstraint::use_preferred_size, true);
        infos.emplace_back(draw::Region{0, 0, 0, 0}, DualLayoutConstraint::use_all_available_space, true);

        Layout.doLayout(rgn, infos);

        CheckBoxPainter::paint(gfx, infos[0].getOutputRegion(), chk_box, size);

        using namespace clsn::ui::painters;
        PaintingInfo info{TextHorizontalAlignment::left, TextVerticalAlignment::middle};

        LabelPainter::paint(gfx, infos[1].getOutputRegion(), chk_box, info);
    }
}