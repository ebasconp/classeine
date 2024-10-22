#pragma once

// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/Forward.h>

#include <clsn/ui/VBoxLayoutContainer.h>

namespace clsn::ui::events
{
    class ActionEvent;
}

namespace clsn::demo
{
    class demo_window;

    class demo_option_container : public ui::VBoxLayoutContainer
    {
        std::shared_ptr<ui::Button> m_hbox_demo;
        std::shared_ptr<ui::Button> m_vbox_demo;
        std::shared_ptr<ui::Button> m_dual_demo;
        std::shared_ptr<ui::Button> m_flow_demo;
        std::shared_ptr<ui::Button> m_xy_demo;
        std::shared_ptr<ui::Button> m_controls;

        demo_window& m_demo_window;

    public:
        explicit demo_option_container(demo_window&);

    private:
        void init_options();
        auto init_option(const std::string& name) -> std::shared_ptr<ui::Button>;

        void process_action(const ui::events::ActionEvent& e);
    };
}