// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/_private/tab_control_view_header_button.h>
#include <clsn/ui/_private/tab_control_view_header_button_renderer.h>

#include <clsn/ui/renderers/toggle_button_renderer.h>

namespace clsn::ui::_private
{
    tab_control_view_header_button::tab_control_view_header_button()
    : toggle_control{"tab_control_view_header_button"}
    {
        set_preferred_size(draw::dimension{80, 32});
    }

    auto tab_control_view_header_button::make_default_renderer() const
        -> std::unique_ptr<renderer_base>
    {
        return std::make_unique<tab_control_view_header_button_renderer>();
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