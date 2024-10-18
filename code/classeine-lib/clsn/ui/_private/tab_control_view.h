// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/_private/tab_control_view_header.h>

#include <clsn/ui/dual_layout_container.h>
#include <clsn/ui/forward.h>

namespace clsn::ui::_private
{
    class tab_control_view_header;

    class tab_control_view final : public dual_layout_container
    {
        tab_control& m_tab_control;

        std::shared_ptr<tab_control_view_header> m_header;
        std::shared_ptr<dynamic_content_pane> m_content_pane;

    public:
        explicit tab_control_view(tab_control&);

        void add(tab_page&);
        void set_active_control(const std::shared_ptr<control>& ctrl);
    };
}