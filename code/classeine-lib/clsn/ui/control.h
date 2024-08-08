#pragma once

#include "clsn/ui/graphics.h"

#include "clsn/ui/events/ControlResizedEvent.h"
#include "clsn/ui/events/MouseClickEvent.h"
#include "clsn/ui/events/MouseMovedEvent.h"

#include "clsn/draw/color.h"
#include "clsn/draw/dimension.h"

#include "clsn/core/entity.h"
#include "clsn/core/entity_wrapper.h"
#include "clsn/core/event_listener_list.h"
#include "clsn/core/property.h"

#include <functional>
#include <memory>
#include <optional>
#include <string_view>

namespace clsn::ui
{
    using namespace clsn::core;
    using namespace clsn::draw;
    using namespace clsn::ui::events;

    class IRenderer;
    class window;

    class control : public entity
    {
        event_listener_list<ControlResizedEvent> m_control_resized_listeners;
        event_listener_list<MouseClickEvent> m_mouse_click_listeners;
        event_listener_list<MouseMovedEvent> m_mouse_moved_listeners;

        std::shared_ptr<entity> m_tag;
        mutable std::shared_ptr<IRenderer> m_renderer;

        std::string m_defaultSectionName;

        mutable bool m_invalidated;

        std::optional<std::reference_wrapper<window>> m_parentWindow;

    public:
        explicit control(std::string_view section_name);

        control(const control&) = delete;
        control(control&&) = delete;

        control& operator=(const control&) = delete;
        control& operator=(control&&) = delete;

        CLSN_PROPERTY(actual_position, point, true);
        CLSN_PROPERTY(actual_size, dimension, true);
        CLSN_PROPERTY(background_color, std::optional<color>, true);
        CLSN_BOOL_PROPERTY_VAL(enabled, true, true);
        CLSN_PROPERTY(font, std::optional<font>, true);
        CLSN_PROPERTY(foreground_color, std::optional<color>, true);
        CLSN_PROPERTY(preferred_size, std::optional<dimension>, true);
        CLSN_PROPERTY(text, std::string, true);
        CLSN_BOOL_PROPERTY_VAL(visible, true, true);

        auto get_actual_background_color() const -> const color&;
        auto get_actual_foreground_color() const -> const color&;
        auto get_actual_font() const -> const font&;
        auto get_actual_preferred_size() const -> const dimension&;

        auto operator==(const control&) const -> bool;
        auto operator!=(const control&) const -> bool;

        void add_mouse_click_listener(event_listener<MouseClickEvent> event);
        void notify_mouse_click_event(MouseClickEvent& e);

        void add_mouse_moved_listener(event_listener<MouseMovedEvent> event);
        void notify_mouse_moved_event(MouseMovedEvent& e);

        void paint(graphics& graphics, const region& region) const;

        auto get_default_section_name() const -> std::string_view;

        template <typename TagType, typename... Args>
        void make_tag(Args&... args)
        {
            m_tag = std::make_unique<EntityWrapper<TagType>>(
                std::forward<Args>(args)...);
        }

        template <typename TagType>
        auto get_tag_or_default(const TagType& defValue) const -> const TagType&
        {
            if (m_tag == nullptr)
                return defValue;

            return static_cast<EntityWrapper<TagType>&>(*m_tag).get();
        }

        void set_renderer(const std::shared_ptr<IRenderer>& renderer);

        auto get_renderer() const -> const IRenderer&;
        auto get_renderer() -> IRenderer&;

        virtual void do_layout();

        virtual void invalidate() const noexcept;
        virtual void validate() const noexcept;
        virtual auto is_invalidated() const noexcept -> bool;

        virtual void release_mouse();

        void set_parent_window(std::optional<std::reference_wrapper<window>>);
        auto get_parent_window() -> std::optional<std::reference_wrapper<window>>;
        auto get_parent_window() const -> std::optional<std::reference_wrapper<const window>>;

        auto is_hovered() const -> bool;

        auto contains_point(const point& point) const -> bool;
        virtual auto get_control_by_position(const point& point) const ->
                std::optional<std::reference_wrapper<const control>>;

        template <typename Proc>
        void invoke_in_parent_window(Proc proc)
        {
            if (!m_parentWindow.has_value())
                return;

            proc(m_parentWindow.value().get());
        }

        virtual void load_defaults();

    protected:
        virtual void process_mouse_click_event(events::MouseClickEvent& e);
        virtual void process_mouse_moved_event(events::MouseMovedEvent& e);

    private:
        void init_events();
    };

    using const_control_optional_reference =
            std::optional<std::reference_wrapper<const control>>;

    using control_optional_reference =
        std::optional<std::reference_wrapper<control>>;

}