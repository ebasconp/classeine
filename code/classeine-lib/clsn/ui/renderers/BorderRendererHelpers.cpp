#include "BorderRendererHelpers.h"

#include "clsn/draw/region.h"

namespace clsn::ui::renderers::BorderRendererHelpers
{
    using namespace clsn::draw;

    void drawFlatBorder(Graphics& graphics,
                        const region& region,
                        const color& colorUp,
                        const color& colorDown,
                        int depth,
                        bool up)
    {
        const auto& actualColor = up ? colorUp : colorDown;

        const int px = region.get_position().get_x();
        const int py = region.get_position().get_y();
        const int pw = region.get_size().get_width();
        const int ph = region.get_size().get_height();

        graphics.setDrawColor(actualColor);
        for (int i = 0; i < depth; i++)
        {
            // top
            const point top1{px + i, py + i};
            const point top2{px + pw - i, py + i};

            graphics.drawLine(top1, top2);

            // left
            const point left2{px + i, py + ph - i - 1};
            graphics.drawLine(top1, left2);
        }

        graphics.setDrawColor(actualColor);
        for (int i = 0; i < depth; i++)
        {
            // bottom
            const point bottom1{px + i, py + ph - i - 1};
            const point bottom2{px + pw - i - 1, py + ph - i - 1};

            graphics.drawLine(bottom1, bottom2);

            // right2
            const point right2{px + pw - i - 1, py + i - 1};
            graphics.drawLine(bottom2, right2);
        }
    }

    void drawBeveledBorder(Graphics& graphics,
                           const region& region,
                           const color& colorUp,
                           const color& colorDown,
                           int depth,
                           bool up)
    {
        const auto& actualUp = up ? colorUp : colorDown;
        const auto& actualDown = up ? colorDown : colorUp;

        const int px = region.get_position().get_x();
        const int py = region.get_position().get_y();
        const int pw = region.get_size().get_width();
        const int ph = region.get_size().get_height();

        graphics.setDrawColor(actualUp);
        for (int i = 0; i < depth; i++)
        {
            // top
            const point top1{px + i, py + i};
            const point top2{px + pw - i, py + i};

            graphics.drawLine(top1, top2);

            // left
            const point left2{px + i, py + ph - i - 1};
            graphics.drawLine(top1, left2);
        }

        graphics.setDrawColor(actualDown);
        for (int i = 0; i < depth; i++)
        {
            // bottom
            const point bottom1{px + i, py + ph - i - 1};
            const point bottom2{px + pw - i - 1, py + ph - i - 1};

            graphics.drawLine(bottom1, bottom2);

            // right2
            const point right2{px + pw - i - 1, py + i - 1};
            graphics.drawLine(bottom2, right2);
        }
    }
}