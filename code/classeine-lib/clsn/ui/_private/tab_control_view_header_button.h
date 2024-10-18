// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/radio_button.h>
#include <clsn/ui/tab_page.h>

#include <clsn/core/optional_reference.h>

namespace clsn::ui::_private
{
    class tab_control_view_header_button final : public clsn::ui::radio_button
    {
        core::optional_reference<tab_page> m_page_ref;

    public:
        tab_control_view_header_button();

        void set_page(tab_page& page);

        auto get_page() -> tab_page&;
        auto get_page() const -> const tab_page&;
    };
}