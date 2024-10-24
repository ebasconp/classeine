// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/core/configuration.h>
#include <clsn/core/entity.h>

#include <clsn/draw/color.h>
#include <clsn/draw/dimension.h>
#include <clsn/draw/font.h>


namespace clsn::ui
{
    using ui_theme_defaults = clsn::core::configuration<clsn::draw::color, clsn::draw::dimension, clsn::draw::font>;

    class ui_theme : clsn::core::entity
    {
        ui_theme_defaults m_defaults_by_name;

    public:
        virtual void populate_defaults() = 0;

        template <typename Type>
        void add(std::string_view section_name, std::string_view name, Type&& value)
        {
            m_defaults_by_name.set(section_name, name, std::forward<Type>(value));
        }

        auto get_color(std::string_view section_name, std::string_view name, const clsn::draw::color& error_value = clsn::draw::color{255, 0, 0}) const -> const clsn::draw::color&;
        auto get_dimension(std::string_view section_name, std::string_view name, const clsn::draw::dimension& error_value = clsn::draw::dimension{32, 32}) const -> const clsn::draw::dimension&;
        auto get_font(std::string_view section_name, std::string_view name, const clsn::draw::font& error_value = clsn::draw::font{}) const -> const clsn::draw::font&;
    };
}