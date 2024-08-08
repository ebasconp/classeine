#include "RadioButtonRenderer.h"

#include "clsn/ui/RadioButton.h"
#include "clsn/ui/UIManager.h"

#include "clsn/draw/Region.h"


namespace clsn::ui::renderers
{
    void RadioButtonRenderer::paint(Graphics& graphics,
                   const Region& region,
                   const Control& baseControl) const
    {
        auto& radioButton = static_cast<const RadioButton&>(baseControl);

        auto section_name = radioButton.getDefaultSectionName();

        auto buttonColor = radioButton.isPressed()
            ? Color{192, 192, 192}
        : UIManager::getInstance().getColor(section_name, "controlBackgroundColor");

        graphics.setDrawColor(buttonColor);
        graphics.drawFillRectangle(region);

        m_labelRenderer.paint(graphics, region, radioButton);

        auto textSize = graphics.getTextSize(radioButton.getActualFont(), radioButton.get_text());

        const auto mid = radioButton.get_actual_position().getY() + (region.getHeight() - textSize.getHeight()) / 2;
        const auto size = textSize.getHeight();

        const auto x = 8 + radioButton.get_actual_position().getX();
        const auto y = mid - 1;

        graphics.setDrawColor(Color{0, 0, 255});
        graphics.drawFillCircle({x, y, size, size});
        graphics.drawFillCircle({x + 1, y + 1, size - 2, size - 2});

        const auto backgroundColor = radioButton.isPressed() ? Color{224, 224, 224} : Color{255, 255, 255};
        graphics.setDrawColor(backgroundColor);

        Color white{255, 255, 255};
        graphics.setDrawColor(radioButton.is_checked() ? Color{0, 0, 128} : white); // Black color
        graphics.drawFillCircle({x + 2, y + 2, size - 4, size - 4});

        graphics.setDrawColor(radioButton.is_checked() ? Color{0, 0, 192} : white); // Black color
        graphics.drawFillCircle({x + 3, y + 3, size - 6, size - 6});

        graphics.setDrawColor(radioButton.is_checked() ? Color{128, 255, 128} : white); // Black color
        graphics.drawFillCircle({x + 4, y + 4, size - 8, size - 8});
    }
}