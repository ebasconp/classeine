// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "clsn/core/empty_event.h"
#include "clsn/core/entity.h"
#include "clsn/core/factory.h"
#include "clsn/core/lazy.h"

#include "clsn/ui/control.h" //FORWARD
#include "clsn/ui/ui_theme.h"

#include <typeindex>
#include <unordered_map>


namespace clsn::ui
{
    class ui_skin : public entity
    {
        std::unordered_map<std::string, factory<ui_theme>> m_theme_factories_by_name;

        std::pair<std::string, std::unique_ptr<ui_theme>> m_current_theme;

        event_listener_list<empty_event> m_theme_changed_listeners;

    public:
        virtual ~ui_skin() = default;

        template <typename UIThemeConcreteType>
        void make_theme_and_add(std::string name)
        {
            m_theme_factories_by_name.emplace(
                name,
                make_factory<ui_theme, UIThemeConcreteType>());
        }

        auto install_theme_by_name(const std::string& name) -> bool;

        auto get_color(std::string_view section_name, std::string_view name) -> const color&;
        auto get_dimension(std::string_view section_name, std::string_view name) -> const dimension&;
        auto get_font(std::string_view section_name, std::string_view name) -> const font&;

        auto add_theme_changed_listener(event_listener<empty_event> listener) -> int;
        auto get_current_theme_name() const -> const std::string&;
    };
}