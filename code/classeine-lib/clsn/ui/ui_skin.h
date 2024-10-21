// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "clsn/core/EmptyEvent.h"
#include "clsn/core/Entity.h"
#include "clsn/core/EventListenerList.h"
#include "clsn/core/Factory.h"

#include "clsn/ui/forward.h"
#include "clsn/ui/ui_theme.h"

#include <unordered_map>


namespace clsn::ui
{
    class ui_skin : public clsn::core::Entity
    {
        std::unordered_map<std::string, clsn::core::Factory<ui_theme>> m_theme_factories_by_name;

        std::pair<std::string, std::unique_ptr<ui_theme>> m_current_theme;

        clsn::core::EventListenerList<clsn::core::EmptyEvent> m_theme_changed_listeners;

    public:
        ~ui_skin() override = default;

        template <typename UIThemeConcreteType>
        void make_theme_and_add(std::string name)
        {
            m_theme_factories_by_name.emplace(
                name,
                clsn::core::Factory<ui_theme>::makeFactory<UIThemeConcreteType>());
        }

        auto install_theme_by_name(const std::string& name) -> bool;

        auto get_color(std::string_view sectionName, std::string_view name) -> const clsn::draw::color&;
        auto get_dimension(std::string_view sectionName, std::string_view name) -> const clsn::draw::dimension&;
        auto getFont(std::string_view sectionName, std::string_view name) -> const clsn::draw::font&;

        auto add_theme_changed_listener(clsn::core::EventListener<clsn::core::EmptyEvent> listener) -> int;
        auto get_current_theme_name() const -> const std::string&;
    };
}