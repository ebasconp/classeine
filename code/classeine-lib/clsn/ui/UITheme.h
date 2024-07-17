#pragma once

#include "clsn/core/Configuration.h"
#include "clsn/core/Entity.h"

#include "clsn/draw/Color.h"
#include "clsn/draw/Font.h"

namespace clsn::ui
{
    using namespace clsn::core;
    using namespace clsn::draw;

    using UIThemeDefaults = Configuration<Color, Font>;

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

        auto getColor(std::string_view section_name, std::string_view name, const Color& errorColor = Color{255, 0, 0}) const -> const Color&;
        auto getFont(std::string_view section_name, std::string_view name, const Font& errorFont = Font{}) const -> const Font&;
    };
}