// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "clsn/core/Configuration.h"
#include "clsn/core/Entity.h"

#include "clsn/draw/Color.h"
#include "clsn/draw/Dimension.h"
#include "clsn/draw/Font.h"


namespace clsn::ui
{
    using ui_theme_defaults = clsn::core::Configuration<clsn::draw::Color, clsn::draw::Dimension, clsn::draw::Font>;

    class ui_theme : clsn::core::Entity
    {
        ui_theme_defaults m_defaults_by_name;

    public:
        virtual void populate_defaults() = 0;

        template <typename Type>
        void add(std::string_view sectionName, std::string_view name, Type&& value)
        {
            m_defaults_by_name.set(sectionName, name, std::forward<Type>(value));
        }

        auto getColor(std::string_view sectionName, std::string_view name, const clsn::draw::Color& error_value = clsn::draw::Color{255, 0, 0}) const -> const clsn::draw::Color&;
        auto get_dimension(std::string_view sectionName, std::string_view name, const clsn::draw::Dimension& error_value = clsn::draw::Dimension{32, 32}) const -> const clsn::draw::Dimension&;
        auto getFont(std::string_view sectionName, std::string_view name, const clsn::draw::Font& error_value = clsn::draw::Font{}) const -> const clsn::draw::Font&;
    };
}