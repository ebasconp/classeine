#include "ButtonRenderer.h"

#include "clsn/ui/button.h"
#include "clsn/ui/graphics.h"
#include "clsn/ui/UIManager.h"

#include "clsn/draw/region.h"

#include "BorderRendererHelpers.h"
#include "LabelRendererHelpers.h"

#include <clsn/ui/window.h>

namespace
{
    using namespace clsn::ui;

    color getUltimateBackgroundColor(const button& button, bool is_hovered)
    {
        if (is_hovered)
        {
            return UIManager::getInstance().getColor(button.get_default_section_name(), "controlHoveredBackgroundColor");
        }

        return button.get_actual_background_color();
    }
}

namespace clsn::ui::renderers
{
    using namespace clsn::draw;
    using namespace clsn::ui;

    auto ButtonRenderer::paintAsPressed(const clickable_control& button) const -> bool
    {
        return button.is_pressed();
    }

    void ButtonRenderer::paint(graphics& graphics,
               const region& a_region,
               const control& baseControl) const
    {
        if (!baseControl.is_invalidated())
            return;

        auto& control = static_cast<const clsn::ui::button&>(baseControl);

        const auto section_name = control.get_default_section_name();
        const auto is_hovered = control.is_hovered();

        auto& unhoveredColor =
            UIManager::getInstance().getColor(
                control.get_default_section_name(), "controlBackgroundColor");

        auto& bevelUp = is_hovered ? UIManager::getInstance().getColor(
            section_name, "bevelUpColor") : unhoveredColor;
        auto& bevelDown = is_hovered ? UIManager::getInstance().getColor(
            section_name, "bevelDownColor") : unhoveredColor;

        constexpr int depth = 2;

        const bool pressed = paintAsPressed(control);

        BorderRendererHelpers::drawFlatBorder(
            graphics, a_region, bevelUp, bevelDown, depth, !pressed);

        constexpr int depth2 = depth * 2;

        const region innerRect{a_region.get_x() + depth,
                               a_region.get_y() + depth,
                               a_region.get_width() - depth2,
                               a_region.get_height() - depth2};

        const auto& buttonColor = pressed
            ? UIManager::getInstance().getColor("button", "pressedBackgroundColor")
            : getUltimateBackgroundColor(control, is_hovered);

        graphics.setDrawColor(buttonColor);
        graphics.drawFillRectangle(innerRect);
        if (pressed)
        {
            const region innerRectShifted{innerRect.get_x() + depth,
                                          innerRect.get_y() + depth,
                                          innerRect.get_width() - depth,
                                          innerRect.get_height() - depth};
            LabelRendererHelpers::drawControlText(graphics, baseControl, innerRectShifted);
        }
        else
        {
            LabelRendererHelpers::drawControlText(graphics, baseControl, innerRect);
        }
    }
}