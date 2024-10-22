// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/core/EmptyEvent.h>
#include <clsn/core/Entity.h>
#include <clsn/core/EventListenerList.h>
#include <clsn/core/Factory.h>

#include <clsn/ui/Forward.h>
#include <clsn/ui/UITheme.h>

#include <unordered_map>


namespace clsn::ui
{
    class UISkin : public clsn::core::Entity
    {
        std::unordered_map<std::string, clsn::core::Factory<UITheme>> m_themeFactoriesByName;

        std::pair<std::string, std::unique_ptr<UITheme>> m_currentTheme;

        clsn::core::EventListenerList<clsn::core::EmptyEvent> m_themeChangedListeners;

    public:
        ~UISkin() override = default;

        template <typename UIThemeConcreteType>
        void makeThemeAndAdd(std::string name)
        {
            m_themeFactoriesByName.emplace(
                name,
                clsn::core::Factory<UITheme>::makeFactory<UIThemeConcreteType>());
        }

        auto installThemeByName(const std::string& name) -> bool;

        auto getColor(std::string_view sectionName, std::string_view name) -> const clsn::draw::Color&;
        auto getDimension(std::string_view sectionName, std::string_view name) -> const clsn::draw::Dimension&;
        auto getFont(std::string_view sectionName, std::string_view name) -> const clsn::draw::Font&;

        auto addThemeChangedListener(clsn::core::EventListener<clsn::core::EmptyEvent> listener) -> int;
        auto getCurrentThemeName() const -> const std::string&;
    };
}