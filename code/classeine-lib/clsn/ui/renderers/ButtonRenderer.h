#pragma once

#include "clsn/ui/Graphics.h"

#include "clsn/draw/Colors.h"
#include "clsn/draw/Region.h"

#include "BorderRenderer.h"

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

    class ButtonRenderer
    {
    public:
        template <typename Control>
        void paint(Graphics& graphics,
                   const Region& region,
                   const Control& control)
        {
            graphics.setDrawColor(control.getBackgroundColor());

            BorderRenderer borderRenderer;

            auto sectionName = control.getDefaultSectionName();

            auto& bevelUp = UIManager::getInstance().getDefault<Color>(
                sectionName, "bevelUpColor");
            auto& bevelDown = UIManager::getInstance().getDefault<Color>(
                sectionName, "bevelDownColor");

            constexpr int depth = 4;

            const bool pressed = control.getController().isPressed();
            std::cout << "PRESSED: " << pressed << std::endl;

            borderRenderer.drawBeveledBorder(
                graphics, region, bevelUp, bevelDown, 8, !pressed);

            constexpr int depth2 = depth * 2;

            Region innerRect{region.getX() + depth,
                             region.getY() + depth,
                             region.getWidth() - depth2,
                             region.getHeight() - depth2};
            graphics.setDrawColor(control.getBackgroundColor());
            graphics.drawFillRectangle(innerRect);
        }
    };
}