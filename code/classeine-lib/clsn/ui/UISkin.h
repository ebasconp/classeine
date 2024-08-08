#pragma once

#include "clsn/core/empty_event.h"
#include "clsn/core/entity.h"
#include "clsn/core/factory.h"
#include "clsn/core/lazy.h"

#include "clsn/ui/Control.h" //FORWARD
#include "clsn/ui/UITheme.h"

#include "clsn/ui/IRenderer.h"

#include "clsn/ui/renderers/NullRenderer.h"

#include <typeindex>
#include <unordered_map>


namespace clsn::ui
{
    using namespace clsn::ui::renderers;

    using LazyRenderer = Lazy<std::shared_ptr<IRenderer>>;

    template <typename RendererType>
    LazyRenderer makeLazyRenderer()
    {
        return LazyRenderer
        {
            []() { return std::make_shared<RendererType>(); }
        };
    }

    class UISkin : public entity
    {
        std::unordered_map<std::type_index, LazyRenderer> m_renderersByControlType;
        std::unordered_map<std::string, Factory<UITheme>> m_themeFactoriesByName;

        std::pair<std::string, std::unique_ptr<UITheme>> m_currentTheme;

        event_listener_list<empty_event> m_themeChangedListeners;


    public:
        virtual ~UISkin() = default;

        template <typename ControlType, typename RendererType>
        void makeRendererAndAdd()
        {
            m_renderersByControlType.emplace(std::type_index(typeid(ControlType)), makeLazyRenderer<RendererType>());
        }

        template <typename UIThemeConcreteType>
        void makeThemeAndAdd(std::string name)
        {
            m_themeFactoriesByName.emplace(
                name,
                makeFactory<UITheme, UIThemeConcreteType>());
        }

        auto installThemeByName(const std::string& name) -> bool;

        auto getColor(std::string_view section_name, std::string_view name) -> const Color&;
        auto getDimension(std::string_view section_name, std::string_view name) -> const Dimension&;
        auto get_font(std::string_view section_name, std::string_view name) -> const Font&;

        auto getRendererByControl(const clsn::ui::Control& ctrl) const -> std::shared_ptr<IRenderer>;
        auto addThemeChangedListener(event_listener<empty_event> listener) -> int;
        auto getCurrentThemeName() const -> const std::string&;
    };
}