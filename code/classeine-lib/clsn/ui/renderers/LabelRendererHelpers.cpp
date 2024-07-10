#include "LabelRendererHelpers.h"

#include "clsn/draw/Color.h"
#include "clsn/draw/Region.h"

#include "clsn/ui/Control.h"

namespace clsn::ui::renderers::LabelRendererHelpers
{
    using namespace clsn::draw;

    void drawControlText(Graphics& graphics, const Control& control, const Region& region)
    {
        if (!control.isEnabled())
        {
            graphics.setDrawColor({192, 192, 192});
            graphics.drawText(region + Point{1, 1},
                              control.getFont(),
                              control.getText());
        }

        graphics.setDrawColor(control.isEnabled()
                              ? control.getForegroundColor()
                              : UIManager::getInstance().getDefault<Color>(
                                    "Theme", "disabledForegroundColor")
                          );

        graphics.drawText(region,
                          control.getFont(),
                          control.getText());
    }
}