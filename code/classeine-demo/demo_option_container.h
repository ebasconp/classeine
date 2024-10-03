#pragma once

// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/forward.h>

#include <clsn/ui/vbox_layout_container.h>

namespace clsn::ui::events
{
    class action_event;
}

namespace clsn::demo
{
    class demo_window;

    class demo_option_container : public ui::vbox_layout_container
    {
        std::shared_ptr<ui::button> m_hbox_demo;
        std::shared_ptr<ui::button> m_vbox_demo;
        std::shared_ptr<ui::button> m_dual_demo;
        std::shared_ptr<ui::button> m_flow_demo;
        std::shared_ptr<ui::button> m_xy_demo;
        std::shared_ptr<ui::button> m_controls;
        std::shared_ptr<ui::button> m_tabs;

        demo_window& m_demo_window;

    public:
        explicit demo_option_container(demo_window&);

    private:
        void init_options();
        auto init_option(const std::string& name) -> std::shared_ptr<ui::button>;

        void process_action(const ui::events::action_event& e);
    };
}