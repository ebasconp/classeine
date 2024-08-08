#include "LabelRenderer.h"

#include "LabelRendererHelpers.h"

#include "clsn/ui/Control.h"
#include "clsn/ui/UIManager.h"

namespace clsn::ui::renderers
{
    void LabelRenderer::paint(Graphics& graphics,
                              const region& region,
                              const Control& control) const
    {
        if (!control.isInvalidated())
            return;

        auto section_name = control.getDefaultSectionName();

        auto bc = UIManager::getInstance().getColor(section_name, "containerBackgroundColor");

        graphics.setDrawColor(bc);
        graphics.drawFillRectangle(region);

        LabelRendererHelpers::drawControlText(graphics, control, region);
    }
}
