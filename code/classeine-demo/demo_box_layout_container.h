#pragma once

// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "clsn/ui/button.h"
#include "clsn/ui/empty_control.h"
#include "clsn/ui/label.h"

#include <clsn/draw/colors.h>

namespace clsn::demo
{
    template <typename LayoutContainer>
    class demo_box_layout_container : public LayoutContainer
    {
        std::shared_ptr<clsn::ui::button> m_button;
        std::shared_ptr<clsn::ui::empty_control> m_control;
        std::shared_ptr<clsn::ui::label> m_label;

    public:
        demo_box_layout_container()
        {
            m_button  = this->template make_and_add<button>();
            m_button->set_text("Click me to toggle UI theme");
            m_button->set_background_color(draw::colors::make_red());
            m_button->set_foreground_color(draw::colors::make_white());
            m_button->add_action_listener([](auto&)
            {
                auto& _ui_mgr = ui::ui_manager::get_instance();
                const auto& theme_name = _ui_mgr.get_current_theme_name();
                _ui_mgr.install_theme(theme_name == "light" ? "dark" : "light");
            });

            m_control = this->template make_and_add<empty_control>();
            m_control->set_background_color(draw::colors::make_yellow());

            m_label = this->template make_and_add<label>();
            m_label->set_text("This is a label");
            m_label->set_background_color(draw::colors::make_blue());
            m_label->set_foreground_color(draw::colors::make_white());
        }
    };
}