// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/flow_layout_container.h>

#include <clsn/ui/forward.h>

namespace clsn::ui::_private
{
    class tab_control_view;
    class tab_control_view_header_button;

    class tab_control_view_header final : public clsn::ui::flow_layout_container
    {
        core::optional_reference<tab_control_view> m_view_ref;
        std::vector<std::shared_ptr<tab_control_view_header_button>> m_buttons;

    public:
        tab_control_view_header();

        void add(tab_page& page);
        void set_view(tab_control_view& view);
    };
}