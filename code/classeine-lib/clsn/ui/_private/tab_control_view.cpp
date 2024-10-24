// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/_private/tab_control_view.h>
#include <clsn/ui/_private/tab_control_view_header.h>

#include <clsn/ui/dynamic_content_pane.h>

namespace clsn::ui::_private
{
    tab_control_view::tab_control_view(tab_control& tab_ctrl)
    : m_tab_control{tab_ctrl}
    {
        this->set_orientation(layouts::dual_layout_orientation::vertical);

        m_header = dual_layout_container::add(control::make<tab_control_view_header>(), layouts::dual_layout_constraint::use_preferred_size);
        m_header->set_view(*this);

        m_content_pane = dual_layout_container::add(control::make<dynamic_content_pane>(), layouts::dual_layout_constraint::use_all_available_space);
    }

    void tab_control_view::add(tab_page& page)
    {
        m_header->add(page);
    }

    void tab_control_view::set_active_control(const std::shared_ptr<control>& ctrl)
    {
        m_content_pane->set_inner_control(ctrl);
    }
}