#pragma once

#include "clsn/ui/Button.h"
#include "clsn/ui/Graphics.h"

#include "clsn/draw/Colors.h"
#include "clsn/draw/Region.h"

#include "BorderRenderer.h"
#include "clsn/ui/IRenderer.h"

#include <iostream>

namespace clsn::ui::renderers
{
    using namespace clsn::draw;
    using namespace clsn::ui;

    template <typename LabelRendererType>
    class ButtonRenderer : public IRenderer
    {
        LabelRendererType m_labelRenderer;

    public:
        void paint(Graphics& graphics,
                   const Region& region,
                   const Control& baseControl) const override
        {
            auto& control = static_cast<const clsn::ui::Button&>(baseControl);

            std::cout << "Control: Button; Text: " << control.getText()
                      << std::endl;

            BorderRenderer borderRenderer;

            auto sectionName = control.getDefaultSectionName();

            auto& bevelUp = UIManager::getInstance().getDefault<Color>(
                sectionName, "bevelUpColor");
            auto& bevelDown = UIManager::getInstance().getDefault<Color>(
                sectionName, "bevelDownColor");

            constexpr int depth = 2;

            const bool pressed = control.isPressed();

            borderRenderer.drawBeveledBorder(
                graphics, region, bevelUp, bevelDown, depth, !pressed);

            constexpr int depth2 = depth * 2;

            const Region innerRect{region.getX() + depth,
                                   region.getY() + depth,
                                   region.getWidth() - depth2,
                                   region.getHeight() - depth2};

            const Color& bc = control.isEnabled()
                                  ? control.getBackgroundColor()
                                  : UIManager::getInstance().getDefault<Color>(
                                        "Theme", "disabledBackgroundColor");
            graphics.setDrawColor(bc);
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