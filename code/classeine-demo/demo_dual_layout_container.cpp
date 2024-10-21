#include "demo_dual_layout_container.h"

#include <clsn/ui/button.h>
#include <clsn/ui/label.h>

namespace clsn::demo
{
    demo_dual_layout_container::demo_dual_layout_container()
    {
        auto _label = control::make<ui::label>();
        _label->setCaption("Using all available space");
        this->add(_label, ui::layouts::dual_layout_constraint::use_all_available_space);

        m_button = this->add(control::make<ui::button>(), ui::layouts::dual_layout_constraint::use_preferred_size);
        m_button->setPreferredSize(draw::dimension{200, 0});
        m_button->setCaption("Using preferred size");
    }
}