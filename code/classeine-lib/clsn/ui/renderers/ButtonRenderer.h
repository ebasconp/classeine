#pragma once

#include "clsn/ui/Graphics.h"

#include "clsn/draw/Colors.h"
#include "clsn/draw/Region.h"

#include "BorderRenderer.h"
#include "LabelRenderer.h"

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

    template <typename LabelRendererType>
    class ButtonRenderer
    {
        LabelRendererType m_labelRenderer;

    public:
        template <typename Control>
        void paint(Graphics& graphics,
                   const Region& region,
                   Control& control)
        {
            std::cout << "Control: Button; Text: " << control.getModel().getText() << std::endl;

            graphics.setDrawColor(control.getBackgroundColor());

            BorderRenderer borderRenderer;

            auto sectionName = control.getDefaultSectionName();

            auto& bevelUp = UIManager::getInstance().getDefault<Color>(
                sectionName, "bevelUpColor");
            auto& bevelDown = UIManager::getInstance().getDefault<Color>(
                sectionName, "bevelDownColor");

            constexpr int depth = 2;

            const bool pressed = control.getController().isPressed();

            borderRenderer.drawBeveledBorder(
                graphics, region, bevelUp, bevelDown, depth, !pressed);

            constexpr int depth2 = depth * 2;

            const Region innerRect{region.getX() + depth,
                             region.getY() + depth,
                             region.getWidth() - depth2,
                             region.getHeight() - depth2};
            graphics.setDrawColor(control.getBackgroundColor());
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

    using DefaultButtonRenderer = ButtonRenderer<DefaultLabelRenderer>;
}