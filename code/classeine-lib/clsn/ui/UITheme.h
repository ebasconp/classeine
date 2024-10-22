// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/core/Configuration.h>
#include <clsn/core/Entity.h>

#include <clsn/draw/Color.h>
#include <clsn/draw/Dimension.h>
#include <clsn/draw/Font.h>


namespace clsn::ui
{
    using UIThemeDefaults = clsn::core::Configuration<clsn::draw::Color, clsn::draw::Dimension, clsn::draw::Font>;

    class UITheme : clsn::core::Entity
    {
        UIThemeDefaults m_defaultsByName;

    public:
        virtual void populateDefaults() = 0;

        template <typename Type>
        void add(std::string_view sectionName, std::string_view name, Type&& value)
        {
            m_defaultsByName.set(sectionName, name, std::forward<Type>(value));
        }

        auto getColor(std::string_view sectionName, std::string_view name, const clsn::draw::Color& error_value = clsn::draw::Color{255, 0, 0}) const -> const clsn::draw::Color&;
        auto getDimension(std::string_view sectionName, std::string_view name, const clsn::draw::Dimension& error_value = clsn::draw::Dimension{32, 32}) const -> const clsn::draw::Dimension&;
        auto getFont(std::string_view sectionName, std::string_view name, const clsn::draw::Font& error_value = clsn::draw::Font{}) const -> const clsn::draw::Font&;
    };
}