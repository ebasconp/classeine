#include "LabelRenderer.h"

#include "LabelRendererHelpers.h"

#include "clsn/ui/control.h"
#include "clsn/ui/UIManager.h"

namespace clsn::ui::renderers
{
    void LabelRenderer::paint(graphics& graphics,
                              const region& region,
                              const control& control) const
    {
        if (!control.is_invalidated())
            return;

        auto section_name = control.get_default_section_name();

        auto bc = UIManager::getInstance().getColor(section_name, "containerBackgroundColor");

        graphics.setDrawColor(bc);
        graphics.drawFillRectangle(region);

        LabelRendererHelpers::drawControlText(graphics, control, region);
    }
}
