#include "demo_option_container.h"
#include "demo_window.h"

#include "clsn/draw/dimension.h"

#include "clsn/ui/button.h"
#include "clsn/ui/dynamic_pane.h"

#include "demo_hbox_layout_container.h"

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
        btn->set_action_name(name);
        btn->add_action_listener([this](auto& e) { this->process_action(e); });

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

    void demo_option_container::process_action(const action_event& e)
    {
        const auto& action_name = e.get_action_name();

        m_demo_window.set_title(action_name + " demo");

        if (action_name == "hbox_layout_container")
        {
            m_demo_window.get_content_pane().set_inner_control(make_control<demo_hbox_layout_container>());
        }

    }
}
