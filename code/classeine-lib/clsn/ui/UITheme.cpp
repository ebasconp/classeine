#include "UITheme.h"

namespace
{
    template <typename Type>
    auto getFromDefaults(const clsn::ui::UIThemeDefaults& defaults, std::string_view section_name, std::string_view name, const Type& errorValue) -> const Type&
    {
        const auto value = defaults.get<Type>(section_name, name);
        if (!value.has_value())
        {
            const auto themeValue = defaults.get<Type>("", name);
            if (themeValue.has_value())
                return themeValue->get();

            return errorValue;
        }

        return value->get();
    }
}

namespace clsn::ui
{
    auto UITheme::getColor(std::string_view section_name, std::string_view name, const color& errorValue) const -> const color&
    {
        return getFromDefaults<color>(m_defaultsByName, section_name, name, errorValue);
    }

    auto UITheme::getDimension(std::string_view section_name, std::string_view name, const dimension& errorValue) const -> const dimension&
    {
        return getFromDefaults<dimension>(m_defaultsByName, section_name, name, errorValue);
    }

    auto UITheme::get_font(std::string_view section_name, std::string_view name, const font& errorValue) const -> const font&
    {
        return getFromDefaults<font>(m_defaultsByName, section_name, name, errorValue);
    }
}