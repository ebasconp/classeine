// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/static_content_pane.h>
#include <clsn/ui/tab_page.h>

#include <clsn/ui/_private/tab_control_view.h>

#include <vector>

namespace clsn::ui
{
    class tab_control : public static_content_pane<_private::tab_control_view>
    {
        using base_class = static_content_pane;

        _private::tab_control_view& m_view;
        std::vector<std::shared_ptr<tab_page_base>> m_pages;

    public:
        explicit tab_control();

        template <typename ControlType, typename... Args>
        auto make_and_add(std::string_view name, Args&&... args) -> std::shared_ptr<tab_page_adapter<ControlType>>
        {
            auto ctrl = control::make<ControlType>(std::forward<Args>(args)...);

            auto new_ptr = std::make_shared<tab_page>(name, ctrl);
            m_pages.push_back(new_ptr);

            m_view.add(*new_ptr);

            return std::make_shared<tab_page_adapter<ControlType>>(*new_ptr);
        }
    };
}