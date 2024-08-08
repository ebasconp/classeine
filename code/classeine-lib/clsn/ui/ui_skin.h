#pragma once

#include "clsn/core/empty_event.h"
#include "clsn/core/entity.h"
#include "clsn/core/factory.h"
#include "clsn/core/lazy.h"

#include "clsn/ui/control.h" //FORWARD
#include "clsn/ui/ui_theme.h"

#include "clsn/ui/renderer_base.h"

#include "clsn/ui/renderers/null_renderer.h"

#include <typeindex>
#include <unordered_map>


namespace clsn::ui
{
    using namespace clsn::ui::renderers;

    using lazy_renderer = lazy<std::shared_ptr<renderer_base>>;

    template <typename RendererType>
    lazy_renderer make_lazy_renderer()
    {
        return lazy_renderer
        {
            []() { return std::make_shared<RendererType>(); }
        };
    }

    class ui_skin : public entity
    {
        std::unordered_map<std::type_index, lazy_renderer> m_renderers_by_control_type;
        std::unordered_map<std::string, factory<ui_theme>> m_theme_factories_by_name;

        std::pair<std::string, std::unique_ptr<ui_theme>> m_current_theme;

        event_listener_list<empty_event> m_theme_changed_listeners;

    public:
        virtual ~ui_skin() = default;

        template <typename ControlType, typename RendererType>
        void make_renderer_and_add()
        {
            m_renderers_by_control_type.emplace(std::type_index(typeid(ControlType)), make_lazy_renderer<RendererType>());
        }

        template <typename UIThemeConcreteType>
        void make_theme_and_add(std::string name)
        {
            m_theme_factories_by_name.emplace(
                name,
                make_factory<ui_theme, UIThemeConcreteType>());
        }

        auto install_theme_by_name(const std::string& name) -> bool;

        auto get_color(std::string_view section_name, std::string_view name) -> const color&;
        auto get_dimension(std::string_view section_name, std::string_view name) -> const dimension&;
        auto get_font(std::string_view section_name, std::string_view name) -> const font&;

        auto get_renderer_by_control(const clsn::ui::control& ctrl) const -> std::shared_ptr<renderer_base>;
        auto add_theme_changed_listener(event_listener<empty_event> listener) -> int;
        auto get_current_theme_name() const -> const std::string&;
    };
}