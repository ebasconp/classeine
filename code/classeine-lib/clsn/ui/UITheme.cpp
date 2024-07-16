#include "UITheme.h"

namespace
{
    template <typename Type>
    auto getFromDefaults(const clsn::ui::UIThemeDefaults& defaults, std::string_view sectionName, std::string_view name, const Type& errorValue) -> const Type&
    {
        const auto value = defaults.get<Type>(sectionName, name);
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
    auto UITheme::getColor(std::string_view sectionName, std::string_view name, const Color& errorValue) const -> const Color&
    {
        return getFromDefaults<Color>(m_defaultsByName, sectionName, name, errorValue);
    }

    auto UITheme::getFont(std::string_view sectionName, std::string_view name, const Font& errorValue) const -> const Font&
    {
        return getFromDefaults<Font>(m_defaultsByName, sectionName, name, errorValue);
    }
}