#include "customizable_renderer.h"

namespace clsn::ui::renderers
{
    void customizable_renderer::paint(graphics& gfx,
                              const region& rgn,
                              const control& ctrl) const
    {
        if (m_painter)
            m_painter(gfx, rgn, ctrl);
    }
}
