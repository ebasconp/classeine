// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "demo_option_container.h"
#include "demo_window.h"

#include "clsn/draw/Dimension.h"

#include "clsn/ui/Button.h"
#include "clsn/ui/DynamicContentPane.h"
#include "clsn/ui/HBoxLayoutContainer.h"
#include "clsn/ui/VBoxLayoutContainer.h"

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
        setPreferredSize(Dimension{175, 0});

        init_options();
    }

    auto demo_option_container::init_option(const std::string& name) -> std::shared_ptr<Button>
    {
        auto btn = add(Control::make<Button>());
        btn->setCaption(name);
        btn->setActionName(name);
        btn->addActionListener([this](auto& e) { this->process_action(e); });

        return btn;
    }

    void demo_option_container::init_options()
    {
        m_hbox_demo = init_option("HBoxLayoutContainer");
        m_vbox_demo = init_option("VBoxLayoutContainer");
        m_dual_demo = init_option("DualLayoutContainer");
        m_flow_demo = init_option("FlowLayoutContainer");
        m_xy_demo = init_option("XYLayoutContainer");
        m_controls = init_option("Controls");
    }

    void demo_option_container::process_action(const ActionEvent& e)
    {
        const auto& actionName = e.getActionName();

        m_demo_window.set_title(actionName + " demo");

        if (actionName == "HBoxLayoutContainer")
        {
            m_demo_window.get_content_pane().setInnerControl(Control::make<demo_box_layout_container<HBoxLayoutContainer>>());
            return;
        }

        if (actionName == "VBoxLayoutContainer")
        {
            m_demo_window.get_content_pane().setInnerControl(Control::make<demo_box_layout_container<VBoxLayoutContainer>>());
            return;
        }

        if (actionName == "DualLayoutContainer")
        {
            m_demo_window.get_content_pane().setInnerControl(Control::make<demo_dual_layout_container>());
            return;
        }

        if (actionName == "FlowLayoutContainer")
        {
            m_demo_window.get_content_pane().setInnerControl(Control::make<demo_flow_layout_container>());
            return;
        }

        if (actionName == "XYLayoutContainer")
        {
            m_demo_window.get_content_pane().setInnerControl(Control::make<demo_xy_layout_container>());
            return;
        }

        if (actionName == "Controls")
        {
            m_demo_window.get_content_pane().setInnerControl(Control::make<demo_control_container>());
        }
    }
}
