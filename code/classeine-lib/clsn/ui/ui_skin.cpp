// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "clsn/ui/ui_skin.h"

namespace clsn::ui
{
    using namespace clsn::draw;

    auto ui_skin::install_theme_by_name(const std::string& name) -> bool
    {
        auto it = m_theme_factories_by_name.find(name);
        if (it == m_theme_factories_by_name.end())
            return false;

        m_current_theme = std::make_pair(name, it->second());
        m_current_theme.second->populate_defaults();

        core::EmptyEvent e;
        m_theme_changed_listeners.notify(e);

        return true;
    }

    auto ui_skin::get_color(std::string_view sectionName, std::string_view name) -> const color&
    {
        return m_current_theme.second->get_color(sectionName, name);
    }

    auto ui_skin::get_dimension(std::string_view sectionName, std::string_view name) -> const dimension&
    {
        return m_current_theme.second->get_dimension(sectionName, name);
    }

    auto ui_skin::getFont(std::string_view sectionName, std::string_view name) -> const font&
    {
        return m_current_theme.second->getFont(sectionName, name);
    }

    auto ui_skin::add_theme_changed_listener(core::EventListener<core::EmptyEvent> listener) -> int
    {
        return m_theme_changed_listeners.add(listener);
    }

    auto ui_skin::get_current_theme_name() const -> const std::string&
    {
        return m_current_theme.first;
    }
}