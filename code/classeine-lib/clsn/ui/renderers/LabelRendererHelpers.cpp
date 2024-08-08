#include "LabelRendererHelpers.h"

#include "clsn/draw/color.h"
#include "clsn/draw/region.h"

#include "clsn/ui/Control.h"
#include "clsn/ui/UIManager.h"


namespace clsn::ui::renderers::LabelRendererHelpers
{
    using namespace clsn::draw;

    void drawControlText(Graphics& graphics, const Control& control, const region& region)
    {
        if (!control.is_enabled())
        {
            graphics.setDrawColor({192, 192, 192});
            graphics.drawText(region + point{1, 1},
                              control.getActualFont(),
                              control.get_text());
        }

        graphics.setDrawColor(control.is_enabled()
                              ? control.getActualForegroundColor()
                              : UIManager::getInstance().getColor(
                                    "Theme", "disabledForegroundColor")
                          );

        graphics.drawText(region,
                          control.getActualFont(),
                          control.get_text());
    }
}