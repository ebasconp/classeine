// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/tab_page.h>

namespace clsn::ui
{
    tab_page::tab_page(std::shared_ptr<control> control_ptr, std::string_view name)
    : m_control_ptr{control_ptr}
    , m_name{name}
    , m_visible{true}
    {
    }

    auto tab_page::get_control_ptr() const -> std::shared_ptr<control>
    {
        return m_control_ptr;
    }

    auto tab_page::get_name() const -> const std::string&
    {
        return m_name;
    }

    auto tab_page::is_visible() const -> bool
    {
        return m_visible;
    }
}