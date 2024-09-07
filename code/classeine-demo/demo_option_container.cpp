#include "demo_option_container.h"

#include "clsn/draw/dimension.h"

#include "clsn/ui/button.h"

namespace clsn::demo
{
    using namespace clsn::draw;

    demo_option_container::demo_option_container()
    {
        set_preferred_size(dimension{175, 0});

        init_options();
    }

    void demo_option_container::init_options()
    {
        m_hbox_demo = make_and_add<button>();
        m_hbox_demo->set_text("hbox_layout_container");

        m_vbox_demo = make_and_add<button>();
        m_vbox_demo->set_text("vbox_layout_container");

        m_dual_demo = make_and_add<button>();
        m_dual_demo->set_text("dual_layout_container");

        m_flow_demo = make_and_add<button>();
        m_flow_demo->set_text("flow_layout_container");

        m_xy_demo   = make_and_add<button>();
        m_xy_demo->set_text("xy_layout_container");

        m_controls  = make_and_add<button>();
        m_controls->set_text("Controls");
    }
}
