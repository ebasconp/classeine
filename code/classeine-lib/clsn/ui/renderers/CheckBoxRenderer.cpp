#include "CheckBoxRenderer.h"

#include "clsn/ui/check_box.h"
#include "clsn/ui/ui_manager.h"

#include "clsn/draw/region.h"

namespace clsn::ui::renderers
{
    void CheckBoxRenderer::paint(graphics& graphics,
                   const region& region,
                   const control& baseControl) const
    {
        auto& checkBox = static_cast<const check_box&>(baseControl);
        auto section_name = checkBox.get_default_section_name();

        auto buttonColor = checkBox.is_pressed()
            ? color{192, 192, 192}
            : ui_manager::get_instance().get_color(section_name, "controlBackgroundColor");

        graphics.set_draw_color(buttonColor);
        graphics.draw_fill_rectangle(region);

        m_labelRenderer.paint(graphics, region, checkBox);

        auto textSize = graphics.get_text_size(checkBox.get_actual_font(), checkBox.get_text());

        const auto mid = checkBox.get_actual_position().get_y() + (region.get_height() - textSize.get_height()) / 2;
        const auto size = textSize.get_height();

        const auto x = 8 + checkBox.get_actual_position().get_x();
        const auto y = mid - 1;

        graphics.set_draw_color(color{0, 0, 255});
        graphics.draw_rectangle({x, y, size, size});

        const auto backgroundColor = checkBox.is_pressed() ? color{224, 224, 224} : color{255, 255, 255};
        graphics.set_draw_color(backgroundColor);
        graphics.draw_fill_rectangle({x + 1, mid, size - 2, size - 2});

        if (checkBox.is_checked())
        {
            graphics.set_draw_color({0, 0, 128}); // Black color
            graphics.draw_rectangle({x + 2, y + 2, size - 4, size - 4});

            graphics.set_draw_color({0, 0, 192}); // Black color
            graphics.draw_rectangle({x + 3, y + 3, size - 6, size - 6});

            graphics.set_draw_color({0, 0, 224}); // Black color
            graphics.draw_fill_rectangle({x + 4, y + 4, size - 8, size - 8});
        }
    }
}