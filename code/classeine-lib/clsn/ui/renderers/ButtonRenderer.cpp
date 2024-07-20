#include "ButtonRenderer.h"

#include "clsn/ui/Button.h"
#include "clsn/ui/Graphics.h"
#include "clsn/ui/UIManager.h"

#include "clsn/draw/Region.h"

#include "BorderRendererHelpers.h"
#include "LabelRendererHelpers.h"

namespace clsn::ui::renderers
{
    using namespace clsn::draw;
    using namespace clsn::ui;

    auto ButtonRenderer::paintAsPressed(const ClickableControl& button) const -> bool
    {
        return button.isPressed();
    }

    void ButtonRenderer::doLayout(Control&) const
    {
        // Do nothing
    }

    void ButtonRenderer::paint(Graphics& graphics,
               const Region& region,
               const Control& baseControl) const
    {
        if (!baseControl.isInvalidated())
            return;

        auto& control = static_cast<const clsn::ui::Button&>(baseControl);

        auto sectionName = control.getDefaultSectionName();

        auto& bevelUp = UIManager::getInstance().getColor(
            sectionName, "bevelUpColor");
        auto& bevelDown = UIManager::getInstance().getColor(
            sectionName, "bevelDownColor");

        constexpr int depth = 2;

        const bool pressed = paintAsPressed(control);

        BorderRendererHelpers::drawFlatBorder(
            graphics, region, bevelUp, bevelDown, depth, !pressed);

        constexpr int depth2 = depth * 2;

        const Region innerRect{region.getX() + depth,
                               region.getY() + depth,
                               region.getWidth() - depth2,
                               region.getHeight() - depth2};

        const auto& buttonColor = pressed
            ? UIManager::getInstance().getColor("Button", "pressedBackgroundColor")
            : control.getActualBackgroundColor();

        graphics.setDrawColor(buttonColor);
        graphics.drawFillRectangle(innerRect);
        if (pressed)
        {
            const Region innerRectShifted{innerRect.getX() + depth,
                                          innerRect.getY() + depth,
                                          innerRect.getWidth() - depth,
                                          innerRect.getHeight() - depth};
            LabelRendererHelpers::drawControlText(graphics, baseControl, innerRectShifted);
        }
        else
        {
            LabelRendererHelpers::drawControlText(graphics, baseControl, innerRect);
        }
    }
}