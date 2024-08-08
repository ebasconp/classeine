#include "CheckBoxRenderer.h"

#include "clsn/ui/check_box.h"
#include "clsn/ui/UIManager.h"

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
            : UIManager::getInstance().getColor(section_name, "controlBackgroundColor");

        graphics.setDrawColor(buttonColor);
        graphics.drawFillRectangle(region);

        m_labelRenderer.paint(graphics, region, checkBox);

        auto textSize = graphics.getTextSize(checkBox.get_actual_font(), checkBox.get_text());

        const auto mid = checkBox.get_actual_position().get_y() + (region.get_height() - textSize.get_height()) / 2;
        const auto size = textSize.get_height();

        const auto x = 8 + checkBox.get_actual_position().get_x();
        const auto y = mid - 1;

        graphics.setDrawColor(color{0, 0, 255});
        graphics.drawRectangle({x, y, size, size});

        const auto backgroundColor = checkBox.is_pressed() ? color{224, 224, 224} : color{255, 255, 255};
        graphics.setDrawColor(backgroundColor);
        graphics.drawFillRectangle({x + 1, mid, size - 2, size - 2});

        if (checkBox.is_checked())
        {
            graphics.setDrawColor({0, 0, 128}); // Black color
            graphics.drawRectangle({x + 2, y + 2, size - 4, size - 4});

            graphics.setDrawColor({0, 0, 192}); // Black color
            graphics.drawRectangle({x + 3, y + 3, size - 6, size - 6});

            graphics.setDrawColor({0, 0, 224}); // Black color
            graphics.drawFillRectangle({x + 4, y + 4, size - 8, size - 8});
        }
    }
}