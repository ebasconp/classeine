#include "ui_theme.h"

namespace
{
    template <typename Type>
    auto getFromDefaults(const clsn::ui::ui_theme_defaults& defaults, std::string_view section_name, std::string_view name, const Type& errorValue) -> const Type&
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
    auto ui_theme::get_color(std::string_view section_name, std::string_view name, const color& errorValue) const -> const color&
    {
        return getFromDefaults<color>(m_defaults_by_name, section_name, name, errorValue);
    }

    auto ui_theme::get_dimension(std::string_view section_name, std::string_view name, const dimension& errorValue) const -> const dimension&
    {
        return getFromDefaults<dimension>(m_defaults_by_name, section_name, name, errorValue);
    }

    auto ui_theme::get_font(std::string_view section_name, std::string_view name, const font& errorValue) const -> const font&
    {
        return getFromDefaults<font>(m_defaults_by_name, section_name, name, errorValue);
    }
}