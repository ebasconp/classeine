#include "border_renderer_helpers.h"

#include "clsn/draw/region.h"

namespace clsn::ui::renderers::border_renderer_helpers
{
    using namespace clsn::draw;

    void draw_flat_border(graphics& graphics,
                        const region& region,
                        const color& the_color,
                        int depth)
    {
        int px = region.get_position().get_x();
        int py = region.get_position().get_y();
        int pw = region.get_size().get_width();
        int ph = region.get_size().get_height();

        graphics.set_draw_color(the_color);
        for (int i = 0; i < depth; i++)
        {
            graphics.draw_rectangle({px, py, pw, ph});
            px++;
            py++;
            pw -= 2;
            ph -= 2;
        }
    }

    void draw_beveled_border(graphics& graphics,
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

        graphics.set_draw_color(actualUp);
        for (int i = 0; i < depth; i++)
        {
            // top
            const point top1{px + i, py + i};
            const point top2{px + pw - i, py + i};

            graphics.draw_line(top1, top2);

            // left
            const point left2{px + i, py + ph - i - 1};
            graphics.draw_line(top1, left2);
        }

        graphics.set_draw_color(actualDown);
        for (int i = 0; i < depth; i++)
        {
            // bottom
            const point bottom1{px + i, py + ph - i - 1};
            const point bottom2{px + pw - i - 1, py + ph - i - 1};

            graphics.draw_line(bottom1, bottom2);

            // right2
            const point right2{px + pw - i - 1, py + i - 1};
            graphics.draw_line(bottom2, right2);
        }
    }
}