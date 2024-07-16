#include "UITheme.h"

namespace clsn::ui
{
    void UITheme::addColor(std::string_view sectionName, std::string_view name, Color color)
    {
        m_colorsByName.set(sectionName, name, color);
    }

    auto UITheme::getColor(std::string_view sectionName, std::string_view name, const Color& errorColor) const -> const Color&
    {
        const auto value = m_colorsByName.get<Color>(sectionName, name);
        if (!value.has_value())
        {
            const auto themeValue = m_colorsByName.get<Color>("", name);
            if (themeValue.has_value())
                return themeValue->get();

            return errorColor;
        }

        return value->get();
    }
}