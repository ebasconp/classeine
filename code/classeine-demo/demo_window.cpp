// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "demo_window.h"

#include "clsn/draw/colors.h"
#include "clsn/draw/dimension.h"

#include "clsn/ui/dual_layout_container.h"
#include "clsn/ui/dynamic_content_pane.h"
#include "clsn/ui/label.h"

#include "demo_option_container.h"

namespace clsn::demo
{
    using namespace clsn::draw;
    using namespace clsn::ui;
    using namespace clsn::ui::layouts;

    demo_window::demo_window()
    {
        set_text("Classeine");
        set_size({800, 600});

        init_container();
    }

    auto demo_window::get_content_pane() -> dynamic_content_pane&
    {
        return *m_content_pane;
    }

    void demo_window::init_container()
    {
        m_option_container = control::make<demo_option_container>(*this);

        (*this)().add(m_option_container, dual_layout_constraint::use_preferred_size);

        auto right_container = (*this)().make_and_add<dual_layout_container>(dual_layout_constraint::use_all_available_space);
        right_container->set_orientation(dual_layout_orientation::vertical);

        m_label = right_container->make_and_add<label>(dual_layout_constraint::use_preferred_size);
        m_label->set_preferred_size(dimension{0, 40});
        m_label->set_font(ui_manager::get_instance().get_font("", "default_bold_font").add_size(5));
        m_label->set_background_color(colors::make_white());
        m_label->set_horizontal_alignment(text_horizontal_alignment::center);
        set_title("Classeine Demo");

        m_content_pane = right_container->make_and_add<dynamic_content_pane>(dual_layout_constraint::use_all_available_space);
        m_content_pane->set_background_color(clsn::draw::color{128, 0, 64});
    }

    void demo_window::set_title(const std::string& title)
    {
        m_label->set_text(title);
    }
}