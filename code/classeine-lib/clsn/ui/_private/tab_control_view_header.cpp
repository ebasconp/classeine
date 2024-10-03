// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/_private/tab_control_view.h>
#include <clsn/ui/_private/tab_control_view_header.h>
#include <clsn/ui/_private/tab_control_view_header_button.h>
#include <clsn/ui/tab_page.h>

namespace clsn::ui::_private
{
    tab_control_view_header::tab_control_view_header()
    {
        set_preferred_size(draw::dimension{200, 32});
    }

    void tab_control_view_header::set_view(tab_control_view& view)
    {
        m_view_ref = view;
    }

    void tab_control_view_header::add(tab_page& page)
    {
        auto btn = make_and_add<tab_control_view_header_button>();
        m_buttons.push_back(btn);

        btn->set_page(page);
        btn->add_action_listener([&](auto& e)
        {
            auto& src = static_cast<tab_control_view_header_button&>(e.get_control());
            m_view_ref.get_ref().set_active_control(src.get_page().get_control_ptr());
        });
    }
}
