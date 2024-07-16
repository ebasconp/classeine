#pragma once

#include "clsn/core/Configuration.h"
#include "clsn/core/Entity.h"

#include "clsn/draw/Color.h"

namespace clsn::ui
{
    using namespace clsn::core;
    using namespace clsn::draw;

    using UIThemeDefaults = Configuration<Color>;

    class UITheme : Entity
    {
        UIThemeDefaults m_colorsByName;

    public:
        void addColor(std::string_view section_name, std::string_view name, Color color);
        auto getColor(std::string_view section_name, std::string_view name, const Color& errorColor = Color{255, 0, 0}) const -> const Color&;
    };
}