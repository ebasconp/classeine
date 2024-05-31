#include "LabelRenderer.h"

#include "clsn/ui/Control.h"
#include "clsn/ui/UIManager.h"

namespace clsn::ui::renderers
{
    void LabelRenderer::paint(Graphics& graphics,
                              const Region& region,
                              Control& control)
    {
        graphics.drawText(region,
                          control.getFont(),
                          control.isEnabled()
                              ? control.getForegroundColor()
                              : UIManager::getInstance().getDefault<Color>(
                                    "Theme", "disabledForegroundColor"),
                          control.getText());
    }
}
