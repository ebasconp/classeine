#include "demo_dual_layout_container.h"

#include <clsn/ui/button.h>
#include <clsn/ui/label.h>

namespace clsn::demo
{
    demo_dual_layout_container::demo_dual_layout_container()
    {
        auto _label = (*this).make_and_add<ui::label>(ui::layouts::dual_layout_constraint::use_all_available_space);
        _label->set_caption("Using all available space");

        m_button = (*this).make_and_add<ui::button>(ui::layouts::dual_layout_constraint::use_preferred_size);
        m_button->set_preferred_size(draw::dimension{200, 0});
        m_button->set_caption("Using preferred size");
    }
}