#pragma once

#include "clsn/ui/graphics.h"

#include "clsn/ui/events/control_resized_event.h"
#include "clsn/ui/events/mouse_click_event.h"
#include "clsn/ui/events/mouse_moved_event.h"

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

    class renderer_base;
    class window;

    template <typename T>
    using optional_reference = std::optional<std::reference_wrapper<T>>;

    template <typename T>
    using const_optional_reference = std::optional<std::reference_wrapper<const T>>;

    class control : public entity
    {
        event_listener_list<control_resized_event> m_control_resized_listeners;
        event_listener_list<mouse_click_event> m_mouse_click_listeners;
        event_listener_list<mouse_moved_event> m_mouse_moved_listeners;

        std::shared_ptr<entity> m_tag;
        mutable std::unique_ptr<renderer_base> m_renderer;

        std::string m_default_section_name;

        mutable bool m_invalidated;

        optional_reference<window>  m_parent_window;
        optional_reference<control> m_parent_control;

    protected:
        explicit control(std::string_view section_name);

    public:
        control(const control&) = delete;
        control(control&&) = delete;

        control& operator=(const control&) = delete;
        control& operator=(control&&) = delete;

        ~control() override;

        virtual void set_parent_control(optional_reference<control>);
        auto get_parent_control() -> optional_reference<control>;
        auto get_parent_control() const -> const_optional_reference<control>;

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
        auto get_actual_bounds() const -> region;

        auto operator==(const control&) const -> bool;
        auto operator!=(const control&) const -> bool;

        void add_mouse_click_listener(event_listener<mouse_click_event> event);
        void notify_mouse_click_event(mouse_click_event& e);

        void add_mouse_moved_listener(event_listener<mouse_moved_event> event);
        void notify_mouse_moved_event(mouse_moved_event& e);

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

        void set_renderer(std::unique_ptr<renderer_base>&& renderer) const;

        auto get_renderer() const -> const renderer_base&;
        auto get_renderer() -> renderer_base&;

        virtual void do_layout();

        virtual void invalidate() const noexcept;
        virtual void validate() const noexcept;
        virtual auto is_invalidated() const noexcept -> bool;

        virtual void release_mouse();

        virtual void set_parent_window(optional_reference<window>);
        auto get_parent_window() -> optional_reference<window>;
        auto get_parent_window() const -> const_optional_reference<window>;

        auto is_hovered() const -> bool;

        auto contains_point(const point& point) const -> bool;
        virtual auto get_control_by_position(const point& point) const ->
                std::optional<std::reference_wrapper<const control>>;

        template <typename Proc>
        void invoke_in_parent_window(Proc proc)
        {
            if (!m_parent_window.has_value())
                return;

            proc(m_parent_window.value().get());
        }

        virtual void load_defaults();

        std::string to_string() const override;

    protected:
        virtual void process_mouse_click_event(events::mouse_click_event& e);
        virtual void process_mouse_moved_event(events::mouse_moved_event& e);

        virtual auto make_default_renderer() const -> std::unique_ptr<renderer_base>;

    private:
        void init_control_events();
    };

    template <typename T, typename... Args>
    std::shared_ptr<T> make_control(Args&&... args)
    {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }
}