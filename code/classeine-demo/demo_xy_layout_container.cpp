#include "demo_xy_layout_container.h"

#include <clsn/ui/button.h>
#include <clsn/ui/label.h>

namespace clsn::demo
{
    demo_xy_layout_container::demo_xy_layout_container()
    {
        auto button1 = (*this).make_and_add<ui::button>(draw::point{20, 20});
        button1->set_text("Toggle button 3");
        button1->set_preferred_size(draw::dimension{200, 100});

        auto button2 = (*this).make_and_add<ui::button>(draw::point{320, 20});
        button2->set_text("Button 2");
        button2->set_preferred_size(draw::dimension{100, 100});

        m_button3 = (*this).make_and_add<ui::button>(draw::point{20, 320});
        m_button3->set_text("Button 3");
        m_button3->set_preferred_size(draw::dimension{100, 100});

        button1->add_action_listener([this](auto& )
        {
            m_button3->set_visible(!m_button3->is_visible());
        });
    }
}