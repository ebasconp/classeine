#include "demo_dual_layout_container.h"

#include <clsn/ui/Button.h>
#include <clsn/ui/Label.h>

namespace clsn::demo
{
    demo_dual_layout_container::demo_dual_layout_container()
    {
        auto _label = Control::make<ui::Label>();
        _label->setCaption("Using all available space");
        this->add(_label, ui::layouts::DualLayoutConstraint::use_all_available_space);

        m_button = this->add(Control::make<ui::Button>(), ui::layouts::DualLayoutConstraint::use_preferred_size);
        m_button->setPreferredSize(draw::Dimension{200, 0});
        m_button->setCaption("Using preferred size");
    }
}