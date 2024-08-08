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

    using UIThemeDefaults = configuration<color, dimension, font>;

    class UITheme : entity
    {
        UIThemeDefaults m_defaultsByName;

    public:
        virtual void populateDefaults() = 0;

        template <typename Type>
        void add(std::string_view section_name, std::string_view name, Type&& value)
        {
            m_defaultsByName.set(section_name, name, std::forward<Type>(value));
        }

        auto getColor(std::string_view section_name, std::string_view name, const color& errorValue = color{255, 0, 0}) const -> const color&;
        auto getDimension(std::string_view section_name, std::string_view name, const dimension& errorValue = dimension{32, 32}) const -> const dimension&;
        auto get_font(std::string_view section_name, std::string_view name, const font& errorValue = font{}) const -> const font&;
    };
}