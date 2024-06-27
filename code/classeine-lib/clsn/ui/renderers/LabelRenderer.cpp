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

        const Color& bc = control.isEnabled()
                              ? control.getBackgroundColor()
                              : UIManager::getInstance().getDefault<Color>(
                                    "Theme", "disabledBackgroundColor");
        graphics.setDrawColor(bc);
        graphics.drawFillRectangle(region);

        if (!control.isEnabled())
        {
            graphics.drawText(region + Point{1, 1},
                              control.getFont(),
                              Color{192, 192, 192},
                              control.getText());
        }

        graphics.drawText(region,
                          control.getFont(),
                          control.isEnabled()
                              ? control.getForegroundColor()
                              : UIManager::getInstance().getDefault<Color>(
                                    "Theme", "disabledForegroundColor"),
                          control.getText());
    }
}
