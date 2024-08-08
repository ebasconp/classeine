#include "RadioButtonRenderer.h"

#include "clsn/ui/radio_button.h"
#include "clsn/ui/ui_manager.h"

#include "clsn/draw/region.h"


namespace clsn::ui::renderers
{
    void RadioButtonRenderer::paint(graphics& graphics,
                   const region& region,
                   const control& baseControl) const
    {
        auto& a_radio_button = static_cast<const radio_button&>(baseControl);

        auto section_name = a_radio_button.get_default_section_name();

        auto buttonColor = a_radio_button.is_pressed()
            ? color{192, 192, 192}
        : ui_manager::get_instance().get_color(section_name, "controlBackgroundColor");

        graphics.set_draw_color(buttonColor);
        graphics.draw_fill_rectangle(region);

        m_labelRenderer.paint(graphics, region, a_radio_button);

        auto textSize = graphics.get_text_size(a_radio_button.get_actual_font(), a_radio_button.get_text());

        const auto mid = a_radio_button.get_actual_position().get_y() + (region.get_height() - textSize.get_height()) / 2;
        const auto size = textSize.get_height();

        const auto x = 8 + a_radio_button.get_actual_position().get_x();
        const auto y = mid - 1;

        graphics.set_draw_color(color{0, 0, 255});
        graphics.draw_fill_circle({x, y, size, size});
        graphics.draw_fill_circle({x + 1, y + 1, size - 2, size - 2});

        const auto backgroundColor = a_radio_button.is_pressed() ? color{224, 224, 224} : color{255, 255, 255};
        graphics.set_draw_color(backgroundColor);

        color white{255, 255, 255};
        graphics.set_draw_color(a_radio_button.is_checked() ? color{0, 0, 128} : white); // Black color
        graphics.draw_fill_circle({x + 2, y + 2, size - 4, size - 4});

        graphics.set_draw_color(a_radio_button.is_checked() ? color{0, 0, 192} : white); // Black color
        graphics.draw_fill_circle({x + 3, y + 3, size - 6, size - 6});

        graphics.set_draw_color(a_radio_button.is_checked() ? color{128, 255, 128} : white); // Black color
        graphics.draw_fill_circle({x + 4, y + 4, size - 8, size - 8});
    }
}