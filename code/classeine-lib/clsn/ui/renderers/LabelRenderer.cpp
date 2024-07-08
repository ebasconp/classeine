#include "LabelRenderer.h"

#include "clsn/draw/Region.h"

#include "clsn/ui/Control.h"
#include "clsn/ui/UIManager.h"

namespace clsn::ui::renderers
{
    void LabelRenderer::doLayout(Control&) const
    {
        // Do nothing
    }

    void LabelRenderer::paint(Graphics& graphics,
                              const Region& region,
                              const Control& control) const
    {
        if (!control.isInvalidated())
            return;

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
