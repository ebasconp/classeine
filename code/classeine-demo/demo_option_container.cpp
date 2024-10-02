// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "demo_option_container.h"
#include "demo_window.h"

#include "clsn/draw/dimension.h"

#include "clsn/ui/button.h"
#include "clsn/ui/dynamic_content_pane.h"
#include "clsn/ui/hbox_layout_container.h"
#include "clsn/ui/vbox_layout_container.h"

#include "demo_box_layout_container.h"
#include "demo_control_container.h"
#include "demo_dual_layout_container.h"
#include "demo_flow_layout_container.h"
#include "demo_xy_layout_container.h"

namespace clsn::demo
{
    using namespace clsn::draw;
    using namespace clsn::ui;
    using namespace clsn::ui::events;

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
            m_demo_window.get_content_pane().set_inner_control(control::make<demo_box_layout_container<hbox_layout_container>>());
            return;
        }

        if (action_name == "vbox_layout_container")
        {
            m_demo_window.get_content_pane().set_inner_control(control::make<demo_box_layout_container<vbox_layout_container>>());
            return;
        }

        if (action_name == "dual_layout_container")
        {
            m_demo_window.get_content_pane().set_inner_control(control::make<demo_dual_layout_container>());
            return;
        }

        if (action_name == "flow_layout_container")
        {
            m_demo_window.get_content_pane().set_inner_control(control::make<demo_flow_layout_container>());
            return;
        }

        if (action_name == "xy_layout_container")
        {
            m_demo_window.get_content_pane().set_inner_control(control::make<demo_xy_layout_container>());
            return;
        }

        if (action_name == "Controls")
        {
            m_demo_window.get_content_pane().set_inner_control(control::make<demo_control_container>());
        }
    }
}
