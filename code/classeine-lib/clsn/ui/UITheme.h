#pragma once

#include "clsn/core/configuration.h"
#include "clsn/core/entity.h"

#include "clsn/draw/Color.h"
#include "clsn/draw/Dimension.h"
#include "clsn/draw/Font.h"

namespace clsn::ui
{
    using namespace clsn::core;
    using namespace clsn::draw;

    using UIThemeDefaults = configuration<Color, Dimension, Font>;

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

        auto getColor(std::string_view section_name, std::string_view name, const Color& errorValue = Color{255, 0, 0}) const -> const Color&;
        auto getDimension(std::string_view section_name, std::string_view name, const Dimension& errorValue = Dimension{32, 32}) const -> const Dimension&;
        auto get_font(std::string_view section_name, std::string_view name, const Font& errorValue = Font{}) const -> const Font&;
    };
}