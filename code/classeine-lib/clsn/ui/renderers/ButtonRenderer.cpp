// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "ButtonRenderer.h"

#include "clsn/ui/Button.h"
#include "clsn/ui/Graphics.h"
#include "clsn/ui/UIManager.h"

#include "clsn/draw/Region.h"

#include "clsn/ui/painters/BackgroundPainter.h"
#include "clsn/ui/painters/BorderPainter.h"
#include "clsn/ui/painters/LabelPainter.h"

#include <clsn/ui/Window.h>

namespace
{
    using namespace clsn::draw;
    using namespace clsn::ui;

    Color get_ultimate_background_color(const Button& btn, bool isHovered)
    {
        if (isHovered)
        {
            return UIManager::get_instance()
                    .getColor(btn.getDefaultSectionName(), "controlHoveredBackgroundColor");
        }

        return btn.getActualBackgroundColor();
    }
}

namespace clsn::ui::renderers
{
    using namespace clsn::draw;
    using namespace clsn::ui;

    auto ButtonRenderer::paint_as_pressed(const ClickableControl& btn) const -> bool
    {
       return btn.isPressed();
    }

    void ButtonRenderer::paint(Graphics& gfx,
               const Region& rgn,
               const Control& ctrl) const
    {
        using namespace clsn::ui::painters;

        if (!ctrl.isInvalidated())
            return;

        auto& btn = static_cast<const clsn::ui::Button&>(ctrl);

        // Paint background
        const auto isHovered = btn.isHovered();
        const bool pressed = paint_as_pressed(btn);

        const auto& btn_clr = pressed
             ? UIManager::get_instance().getColor("Button", "pressedBackgroundColor")
             : get_ultimate_background_color(btn, isHovered);

        BackgroundPainter::paint(gfx, rgn, btn_clr);

        // paint border
        const auto sectionName = btn.getDefaultSectionName();

        auto& unhovered_clr =
             UIManager::get_instance().getColor(
                btn.getDefaultSectionName(), "controlBackgroundColor");

        const auto& clr = isHovered
                 ? UIManager::get_instance().getColor(sectionName, "bevelUpColor")
                 : unhovered_clr;

        constexpr int depth = 2;
        BorderPainter::paintFlat(gfx, rgn, clr, depth);

        constexpr int depth2 = depth * 2;

        const Region inner_rect = rgn + Region{depth, depth, -depth2, -depth2};

        using namespace clsn::ui::painters;
        PaintingInfo info{TextHorizontalAlignment::center, TextVerticalAlignment::middle};

        if (pressed)
        {
            const Region inner_rect_shifted = inner_rect + Region{depth, depth, -depth, -depth};
            LabelPainter::paint(gfx, inner_rect_shifted, btn, info);
        }
        else
        {
            LabelPainter::paint(gfx, inner_rect, btn, info);
        }
    }
}