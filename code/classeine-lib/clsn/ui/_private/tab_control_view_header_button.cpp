// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/_private/tab_control_view_header_button.h>

namespace clsn::ui::_private
{
    tab_control_view_header_button::tab_control_view_header_button()
    {
        set_preferred_size(draw::dimension{80, 32});
    }

    void tab_control_view_header_button::set_page(tab_page& page)
    {
        m_page_ref = page;
        set_caption(page.get_name());
    }

    auto tab_control_view_header_button::get_page() -> tab_page&
    {
        return m_page_ref.get_ref();
    }

    auto tab_control_view_header_button::get_page() const -> const tab_page&
    {
        return m_page_ref.get_ref();
    }

}