#include "clsn/ui/UISkin.h"

namespace clsn::ui
{
    auto UISkin::installThemeByName(const std::string& name) -> bool
    {
        auto it = m_themeFactoriesByName.find(name);
        if (it == m_themeFactoriesByName.end())
            return false;

        m_currentTheme = std::make_pair(name, it->second());
        m_currentTheme.second->populateDefaults();

        EmptyEvent e;
        m_themeChangedListeners.notify(e);

        return true;
    }

    auto UISkin::getColor(std::string_view sectionName, std::string_view name) -> const Color&
    {
        return m_currentTheme.second->getColor(sectionName, name);
    }

    auto UISkin::getDimension(std::string_view sectionName, std::string_view name) -> const Dimension&
    {
        return m_currentTheme.second->getDimension(sectionName, name);
    }

    auto UISkin::getFont(std::string_view sectionName, std::string_view name) -> const Font&
    {
        return m_currentTheme.second->getFont(sectionName, name);
    }

    auto UISkin::getRendererByControl(const clsn::ui::Control& ctrl) const -> std::shared_ptr<IRenderer>
    {
        auto it = m_renderersByControlType.find(std::type_index(typeid(ctrl)));
        if (it == nullptr)
            return std::make_shared<NullRenderer>();

        return it->second.get();
    }

    auto UISkin::addThemeChangedListener(EventListener<EmptyEvent> listener) -> int
    {
        return m_themeChangedListeners.add(listener);
    }

    auto UISkin::getCurrentThemeName() const -> const std::string&
    {
        return m_currentTheme.first;
    }
}