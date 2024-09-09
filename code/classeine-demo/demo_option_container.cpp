#include "demo_option_container.h"
#include "demo_window.h"

#include "clsn/draw/dimension.h"

#include "clsn/ui/button.h"

namespace clsn::demo
{
    using namespace clsn::draw;

    demo_option_container::demo_option_container(demo_window& demo_window)
    : m_demo_window{demo_window}
    {
        set_preferred_size(dimension{175, 0});

        init_options();
    }

    auto demo_option_container::init_option(const std::string& name) -> std::shared_ptr<button>
    {
        auto btn = make_and_add<button>();
        btn->set_text(name);
        btn->add_action_listener([this](auto& ) { this->process_action(); });

        return btn;
    }

    void demo_option_container::init_options()
    {
        m_hbox_demo = init_option("hbox_layout_container");
        m_vbox_demo = init_option("vbox_layout_container");
        m_dual_demo = init_option("dual_layout_container");
        m_flow_demo = init_option("flow_layout_container");
        m_xy_demo = init_option("xy_layout_container");
        m_controls = init_option("Controls");
    }

    void demo_option_container::process_action()
    {

    }
}
