#include "RadioButtonRenderer.h"

#include "clsn/ui/RadioButton.h"

#include "clsn/draw/Region.h"

namespace clsn::ui::renderers
{
    void RadioButtonRenderer::doLayout(Control& ) const
    {
        // Do nothing
    }

    void RadioButtonRenderer::paint(Graphics& graphics,
                   const Region& region,
                   const Control& baseControl) const
    {
        auto& radioButton = static_cast<const RadioButton&>(baseControl);

        m_labelRenderer.paint(graphics, region, radioButton);

        auto textSize = graphics.getTextSize(radioButton.getFont(), radioButton.getText());

        const auto mid = radioButton.getLocation().getY() + (region.getHeight() - textSize.getHeight()) / 2;
        const auto size = textSize.getHeight();

        const auto x = 8 + radioButton.getLocation().getX();
        const auto y = mid - 1;

        graphics.setDrawColor(Color{0, 0, 255});
        graphics.drawCircle({x, y}, size);

        const auto backgroundColor = radioButton.isPressed() ? Color{224, 224, 224} : Color{255, 255, 255};
        graphics.setDrawColor(backgroundColor);
        graphics.drawCircle({x + 1, mid}, size - 2);

        Color white{255, 255, 255};
        graphics.setDrawColor(radioButton.isChecked() ? Color{0, 0, 128} : white); // Black color
        graphics.drawCircle({x + 2, y + 2}, size - 4);

        graphics.setDrawColor(radioButton.isChecked() ? Color{0, 0, 192} : white); // Black color
        graphics.drawCircle({x + 3, y + 3}, size - 6);

        graphics.setDrawColor(radioButton.isChecked() ? Color{0, 0, 224} : white); // Black color
        graphics.drawCircle({x + 4, y + 4}, size - 8);
    }
}