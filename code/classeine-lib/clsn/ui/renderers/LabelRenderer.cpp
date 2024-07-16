#include "LabelRenderer.h"

#include "LabelRendererHelpers.h"

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

        auto sectionName = control.getDefaultSectionName();

        auto bc = UIManager::getInstance().getColor(sectionName, "containerBackgroundColor");

        graphics.setDrawColor(bc);
        graphics.drawFillRectangle(region);

        LabelRendererHelpers::drawControlText(graphics, control, region);
    }
}
