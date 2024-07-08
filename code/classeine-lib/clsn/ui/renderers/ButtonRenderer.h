#pragma once

#include "clsn/ui/Button.h"
#include "clsn/ui/Graphics.h"

#include "clsn/draw/Region.h"

#include "BorderRenderer.h"
#include "clsn/ui/IRenderer.h"

namespace clsn::ui::renderers
{
    using namespace clsn::draw;
    using namespace clsn::ui;

    template <typename LabelRendererType>
    class ButtonRenderer : public IRenderer
    {
        LabelRendererType m_labelRenderer;

    public:
        [[nodiscard]] virtual auto paintAsPressed(const ClickableControl& button) const -> bool
        {
            return button.isPressed();
        }

        void doLayout(Control&) const override
        {
            // Do nothing
        }

        void paint(Graphics& graphics,
                   const Region& region,
                   const Control& baseControl) const override
        {
            if (!baseControl.isInvalidated())
                return;

            auto& control = static_cast<const clsn::ui::Button&>(baseControl);

            BorderRenderer borderRenderer;

            auto sectionName = control.getDefaultSectionName();

            auto& bevelUp = UIManager::getInstance().getDefault<Color>(
                sectionName, "bevelUpColor");
            auto& bevelDown = UIManager::getInstance().getDefault<Color>(
                sectionName, "bevelDownColor");

            constexpr int depth = 2;

            const bool pressed = paintAsPressed(control);

            borderRenderer.drawFlatBorder(
                graphics, region, bevelUp, bevelDown, depth, !pressed);

            constexpr int depth2 = depth * 2;

            const Region innerRect{region.getX() + depth,
                                   region.getY() + depth,
                                   region.getWidth() - depth2,
                                   region.getHeight() - depth2};

            auto buttonColor = pressed
                ? Color{192, 192, 192}
                : UIManager::getInstance().getDefault<Color>(sectionName, "controlBackgroundColor");

            graphics.setDrawColor(buttonColor);
            graphics.drawFillRectangle(innerRect);
            if (pressed)
            {
                const Region innerRectShifted{innerRect.getX() + depth,
                                              innerRect.getY() + depth,
                                              innerRect.getWidth() - depth,
                                              innerRect.getHeight() - depth};
                m_labelRenderer.paint(graphics, innerRectShifted, control);
            }
            else
            {
                m_labelRenderer.paint(graphics, innerRect, control);
            }
        }
    };
}