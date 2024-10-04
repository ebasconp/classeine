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
        std::vector<std::unique_ptr<tab_page>> m_pages;

    public:
        explicit tab_control();

        template <typename ControlType>
        auto add(std::string_view name, const std::shared_ptr<ControlType>& ctrl_ptr) -> std::pair<tab_page&, std::shared_ptr<ControlType>>
        {
            auto& page = m_pages.emplace_back(std::make_unique<tab_page>(ctrl_ptr, name));

            m_view.add(*page);

            return {*page, ctrl_ptr};
        }

        template <typename ControlType, typename... Args>
        auto make_and_add(std::string_view name, Args&&... args) -> std::pair<tab_page&, std::shared_ptr<ControlType>>
        {
            auto ctrl_ptr = control::make<ControlType>(std::forward<Args>(args)...);
            return add(name, ctrl_ptr);
        }
    };
}