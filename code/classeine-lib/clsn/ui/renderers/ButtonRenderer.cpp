#include "ButtonRenderer.h"

#include "clsn/ui/Button.h"
#include "clsn/ui/Graphics.h"
#include "clsn/ui/UIManager.h"

#include "clsn/draw/region.h"

#include "BorderRendererHelpers.h"
#include "LabelRendererHelpers.h"

#include <clsn/ui/Window.h>

namespace
{
    using namespace clsn::ui;

    color getUltimateBackgroundColor(const Button& button, bool isHovered)
    {
        if (isHovered)
        {
            return UIManager::getInstance().getColor(button.getDefaultSectionName(), "controlHoveredBackgroundColor");
        }

        return button.getActualBackgroundColor();
    }
}

namespace clsn::ui::renderers
{
    using namespace clsn::draw;
    using namespace clsn::ui;

    auto ButtonRenderer::paintAsPressed(const ClickableControl& button) const -> bool
    {
        return button.isPressed();
    }

    void ButtonRenderer::paint(Graphics& graphics,
               const region& a_region,
               const Control& baseControl) const
    {
        if (!baseControl.isInvalidated())
            return;

        auto& control = static_cast<const clsn::ui::Button&>(baseControl);

        const auto section_name = control.getDefaultSectionName();
        const auto isHovered = control.isHovered();

        auto& unhoveredColor =
            UIManager::getInstance().getColor(
                control.getDefaultSectionName(), "controlBackgroundColor");

        auto& bevelUp = isHovered ? UIManager::getInstance().getColor(
            section_name, "bevelUpColor") : unhoveredColor;
        auto& bevelDown = isHovered ? UIManager::getInstance().getColor(
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
            ? UIManager::getInstance().getColor("Button", "pressedBackgroundColor")
            : getUltimateBackgroundColor(control, isHovered);

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