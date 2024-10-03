// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/control.h>

#include <memory>

namespace clsn::ui
{
    class tab_page final
    {
        std::shared_ptr<control> m_control_ptr;
        std::string m_name;
        bool m_visible;

    public:
        tab_page(std::shared_ptr<control> control_ptr, std::string_view name);

        auto get_control_ptr() const -> std::shared_ptr<control>;
        auto get_name() const -> const std::string&;
        auto is_visible() const -> bool;

    };
}