#include "CheckBoxRenderer.h"

#include "clsn/ui/CheckBox.h"
#include "clsn/ui/UIManager.h"

#include "clsn/draw/Region.h"

namespace clsn::ui::renderers
{
    void CheckBoxRenderer::paint(Graphics& graphics,
                   const Region& region,
                   const Control& baseControl) const
    {
        auto& checkBox = static_cast<const CheckBox&>(baseControl);
        auto section_name = checkBox.getDefaultSectionName();

        auto buttonColor = checkBox.isPressed()
            ? Color{192, 192, 192}
            : UIManager::getInstance().getColor(section_name, "controlBackgroundColor");

        graphics.setDrawColor(buttonColor);
        graphics.drawFillRectangle(region);

        m_labelRenderer.paint(graphics, region, checkBox);

        auto textSize = graphics.getTextSize(checkBox.getActualFont(), checkBox.get_text());

        const auto mid = checkBox.get_actual_position().getY() + (region.getHeight() - textSize.getHeight()) / 2;
        const auto size = textSize.getHeight();

        const auto x = 8 + checkBox.get_actual_position().getX();
        const auto y = mid - 1;

        graphics.setDrawColor(Color{0, 0, 255});
        graphics.drawRectangle({x, y, size, size});

        const auto backgroundColor = checkBox.isPressed() ? Color{224, 224, 224} : Color{255, 255, 255};
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