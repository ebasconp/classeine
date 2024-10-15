// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/control.h>

#include <memory>

namespace clsn::ui
{
    class tab_page_base
    {
    public:
        virtual ~tab_page_base() = default;

        [[nodiscard]] virtual auto get_name() const -> const std::string& = 0;
        [[nodiscard]] virtual auto is_visible() const -> bool = 0;
    };

    class tab_page final : public tab_page_base
    {
        std::string m_name;
        bool m_visible;
        std::shared_ptr<control> m_control_ptr;

    public:
        explicit tab_page(std::string_view name, std::shared_ptr<control> control_ptr);

        [[nodiscard]] auto get_control_ptr() -> std::shared_ptr<control>;
        [[nodiscard]] auto get_control_ptr() const -> const std::shared_ptr<control>;

        [[nodiscard]] auto get_name() const -> const std::string& override;
        [[nodiscard]] auto is_visible() const -> bool override;
    };

    template <typename ControlType>
    class tab_page_adapter final : public tab_page_base
    {
        tab_page& m_tab_page;

    public:
        explicit tab_page_adapter(tab_page& tab_page)
        : m_tab_page{tab_page}
        {
        }

        [[nodiscard]] auto get_control_ptr() -> std::shared_ptr<ControlType>
        {
            return std::static_pointer_cast<ControlType>(m_tab_page.get_control_ptr());
        }

        [[nodiscard]] auto get_control_ptr() const -> const std::shared_ptr<ControlType>
        {
            return std::static_pointer_cast<ControlType>(m_tab_page.get_control_ptr());
        }

        [[nodiscard]] auto get_name() const -> const std::string& override
        {
            return m_tab_page.get_name();
        }

        [[nodiscard]] auto is_visible() const -> bool override
        {
            return m_tab_page.is_visible();
        }
    };
}