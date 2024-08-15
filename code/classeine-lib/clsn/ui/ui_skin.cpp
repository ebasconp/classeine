#include "clsn/ui/ui_skin.h"

namespace clsn::ui
{
    auto ui_skin::install_theme_by_name(const std::string& name) -> bool
    {
        auto it = m_theme_factories_by_name.find(name);
        if (it == m_theme_factories_by_name.end())
            return false;

        m_current_theme = std::make_pair(name, it->second());
        m_current_theme.second->populate_defaults();

        empty_event e;
        m_theme_changed_listeners.notify(e);

        return true;
    }

    auto ui_skin::get_color(std::string_view section_name, std::string_view name) -> const color&
    {
        return m_current_theme.second->get_color(section_name, name);
    }

    auto ui_skin::get_dimension(std::string_view section_name, std::string_view name) -> const dimension&
    {
        return m_current_theme.second->get_dimension(section_name, name);
    }

    auto ui_skin::get_font(std::string_view section_name, std::string_view name) -> const font&
    {
        return m_current_theme.second->get_font(section_name, name);
    }

    auto ui_skin::add_theme_changed_listener(event_listener<empty_event> listener) -> int
    {
        return m_theme_changed_listeners.add(listener);
    }

    auto ui_skin::get_current_theme_name() const -> const std::string&
    {
        return m_current_theme.first;
    }
}