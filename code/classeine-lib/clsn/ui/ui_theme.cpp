// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "ui_theme.h"

namespace
{
    template <typename Type>
    auto get_from_defaults(const clsn::ui::ui_theme_defaults& defaults, std::string_view section_name, std::string_view name, const Type& error_value) -> const Type&
    {
        const auto value = defaults.get<Type>(section_name, name);
        if (!value.has_value())
        {
            const auto theme_value = defaults.get<Type>("", name);
            if (theme_value.has_value())
                return theme_value->get();

            return error_value;
        }

        return value->get();
    }
}

namespace clsn::ui
{
    using namespace clsn::draw;

    auto ui_theme::get_color(std::string_view section_name, std::string_view name, const color& error_value) const -> const color&
    {
        return get_from_defaults<color>(m_defaults_by_name, section_name, name, error_value);
    }

    auto ui_theme::get_dimension(std::string_view section_name, std::string_view name, const dimension& error_value) const -> const dimension&
    {
        return get_from_defaults<dimension>(m_defaults_by_name, section_name, name, error_value);
    }

    auto ui_theme::get_font(std::string_view section_name, std::string_view name, const font& error_value) const -> const font&
    {
        return get_from_defaults<font>(m_defaults_by_name, section_name, name, error_value);
    }
}