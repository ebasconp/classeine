#include "demo_hbox_layout_container.h"

#include "clsn/ui/button.h"
#include "clsn/ui/empty_control.h"
#include "clsn/ui/label.h"

namespace clsn::demo
{
    using namespace clsn::ui;

    demo_hbox_layout_container::demo_hbox_layout_container()
    {
        m_button  = make_and_add<button>();
        m_button->set_text("Click me");

        m_control = make_and_add<empty_control>();

        m_label   = make_and_add<label>();
        m_label->set_background_color(clsn::draw::color{140, 0, 60});
    }
}