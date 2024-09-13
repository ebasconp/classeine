// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "clsn/core/configuration.h"
#include "clsn/core/entity.h"

#include "clsn/draw/color.h"
#include "clsn/draw/dimension.h"
#include "clsn/draw/font.h"

namespace clsn::ui
{
    using namespace clsn::core;
    using namespace clsn::draw;

    using ui_theme_defaults = configuration<color, dimension, font>;

    class ui_theme : entity
    {
        ui_theme_defaults m_defaults_by_name;

    public:
        virtual void populate_defaults() = 0;

        template <typename Type>
        void add(std::string_view section_name, std::string_view name, Type&& value)
        {
            m_defaults_by_name.set(section_name, name, std::forward<Type>(value));
        }

        auto get_color(std::string_view section_name, std::string_view name, const color& error_value = color{255, 0, 0}) const -> const color&;
        auto get_dimension(std::string_view section_name, std::string_view name, const dimension& error_value = dimension{32, 32}) const -> const dimension&;
        auto get_font(std::string_view section_name, std::string_view name, const font& error_value = font{}) const -> const font&;
    };
}