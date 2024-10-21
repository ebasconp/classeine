#include "demo_xy_layout_container.h"

#include <clsn/ui/button.h>
#include <clsn/ui/label.h>

namespace clsn::demo
{
    demo_xy_layout_container::demo_xy_layout_container()
    {
        auto button1 = this->add(control::make<ui::button>(), draw::Point{20, 20});
        button1->setCaption("Toggle button 3");
        button1->setPreferredSize(draw::Dimension{200, 100});

        auto button2 = this->add(control::make<ui::button>(), draw::Point{320, 20});
        button2->setCaption("Button 2");
        button2->setPreferredSize(draw::Dimension{100, 100});

        m_button3 = this->add(control::make<ui::button>(), draw::Point{20, 320});
        m_button3->setCaption("Button 3");
        m_button3->setPreferredSize(draw::Dimension{100, 100});

        button1->add_action_listener([this](auto& )
        {
            m_button3->setVisible(!m_button3->isVisible());
        });
    }
}