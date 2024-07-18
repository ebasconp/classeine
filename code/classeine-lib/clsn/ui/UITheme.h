#pragma once

#include "clsn/core/Configuration.h"
#include "clsn/core/Entity.h"

#include "clsn/draw/Color.h"
#include "clsn/draw/Dimension.h"
#include "clsn/draw/Font.h"

namespace clsn::ui
{
    using namespace clsn::core;
    using namespace clsn::draw;

    using UIThemeDefaults = Configuration<Color, Dimension, Font>;

    class UITheme : Entity
    {
        UIThemeDefaults m_defaultsByName;

    public:
        virtual void populateDefaults() = 0;

        template <typename Type>
        void add(std::string_view sectionName, std::string_view name, Type&& value)
        {
            m_defaultsByName.set(sectionName, name, std::forward<Type>(value));
        }

        auto getColor(std::string_view section_name, std::string_view name, const Color& errorValue = Color{255, 0, 0}) const -> const Color&;
        auto getDimension(std::string_view section_name, std::string_view name, const Dimension& errorValue = Dimension{32, 32}) const -> const Dimension&;
        auto getFont(std::string_view section_name, std::string_view name, const Font& errorValue = Font{}) const -> const Font&;
    };
}