// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "UITheme.h"

#include <clsn/core/Console.h>

namespace
{
    template <typename Type>
    auto get_from_defaults(const clsn::ui::UIThemeDefaults& defaults, std::string_view sectionName, std::string_view name, const Type& error_value) -> const Type&
    {
        const auto value = defaults.get<Type>(sectionName, name);
        if (!value.has_value())
        {
            const auto theme_value = defaults.get<Type>("", name);
            if (theme_value.has_value())
                return theme_value->get();

            clsn::core::Console::debug("Key [{}] not found", name);
            return error_value;
        }

        return value->get();
    }
}

namespace clsn::ui
{
    using namespace clsn::draw;

    auto UITheme::getColor(std::string_view sectionName, std::string_view name, const Color& error_value) const -> const Color&
    {
        return get_from_defaults<Color>(m_defaultsByName, sectionName, name, error_value);
    }

    auto UITheme::getDimension(std::string_view sectionName, std::string_view name, const Dimension& error_value) const -> const Dimension&
    {
        return get_from_defaults<Dimension>(m_defaultsByName, sectionName, name, error_value);
    }

    auto UITheme::getFont(std::string_view sectionName, std::string_view name, const Font& error_value) const -> const Font&
    {
        return get_from_defaults<Font>(m_defaultsByName, sectionName, name, error_value);
    }
}