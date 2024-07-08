#include "BorderRenderer.h"

#include "clsn/draw/Region.h"

namespace clsn::ui::renderers
{
    using namespace clsn::draw;

    void BorderRenderer::drawFlatBorder(Graphics& graphics,
                                           const Region& region,
                                           const Color& colorUp,
                                           const Color& colorDown,
                                           int depth,
                                           bool up)
    {
        const auto& actualColor = up ? colorUp : colorDown;

        const int px = region.getPosition().getX();
        const int py = region.getPosition().getY();
        const int pw = region.getSize().getWidth();
        const int ph = region.getSize().getHeight();

        graphics.setDrawColor(actualColor);
        for (int i = 0; i < depth; i++)
        {
            // top
            const Point top1{px + i, py + i};
            const Point top2{px + pw - i, py + i};

            graphics.drawLine(top1, top2);

            // left
            const Point left2{px + i, py + ph - i - 1};
            graphics.drawLine(top1, left2);
        }

        graphics.setDrawColor(actualColor);
        for (int i = 0; i < depth; i++)
        {
            // bottom
            const Point bottom1{px + i, py + ph - i - 1};
            const Point bottom2{px + pw - i - 1, py + ph - i - 1};

            graphics.drawLine(bottom1, bottom2);

            // right2
            const Point right2{px + pw - i - 1, py + i - 1};
            graphics.drawLine(bottom2, right2);
        }
    }

    void BorderRenderer::drawBeveledBorder(Graphics& graphics,
                                           const Region& region,
                                           const Color& colorUp,
                                           const Color& colorDown,
                                           int depth,
                                           bool up)
    {
        const auto& actualUp = up ? colorUp : colorDown;
        const auto& actualDown = up ? colorDown : colorUp;

        const int px = region.getPosition().getX();
        const int py = region.getPosition().getY();
        const int pw = region.getSize().getWidth();
        const int ph = region.getSize().getHeight();

        graphics.setDrawColor(actualUp);
        for (int i = 0; i < depth; i++)
        {
            // top
            const Point top1{px + i, py + i};
            const Point top2{px + pw - i, py + i};

            graphics.drawLine(top1, top2);

            // left
            const Point left2{px + i, py + ph - i - 1};
            graphics.drawLine(top1, left2);
        }

        graphics.setDrawColor(actualDown);
        for (int i = 0; i < depth; i++)
        {
            // bottom
            const Point bottom1{px + i, py + ph - i - 1};
            const Point bottom2{px + pw - i - 1, py + ph - i - 1};

            graphics.drawLine(bottom1, bottom2);

            // right2
            const Point right2{px + pw - i - 1, py + i - 1};
            graphics.drawLine(bottom2, right2);
        }
    }
}