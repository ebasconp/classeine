// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/graphics.h>

#include <clsn/ui/events/control_resized_event.h>
#include <clsn/ui/events/mouse_click_event.h>
#include <clsn/ui/events/mouse_moved_event.h>

#include <clsn/draw/dimension.h>

#include <clsn/core/entity.h>
#include <clsn/core/entity_wrapper.h>
#include <clsn/core/event_listener_list.h>
#include <clsn/core/optional_reference.h>
#include <clsn/core/property.h>

#include <functional>
#include <memory>
#include <optional>
#include <string_view>

namespace clsn::ui
{
    class renderer_base;
    class window;

    /// Base class for all controls (referred to as UI widgets) in *classeine*.
    ///
    /// This class provides basic methods for handling events and
    /// offers the infrastructure for managing rendering and layouts.
    class control : public clsn::core::entity
    {
        clsn::core::event_listener_list<clsn::ui::events::control_resized_event> m_control_resized_listeners;
        clsn::core::event_listener_list<clsn::ui::events::mouse_click_event> m_mouse_click_listeners;
        clsn::core::event_listener_list<clsn::ui::events::mouse_moved_event> m_mouse_moved_listeners;

        std::shared_ptr<clsn::core::entity> m_tag;
        mutable std::unique_ptr<renderer_base> m_renderer;

        std::string m_default_section_name;

        mutable bool m_invalidated;

        core::optional_reference<window>  m_parent_window;
        core::optional_reference<control> m_parent_control;

    protected:
        explicit control(std::string_view section_name);

    public:
        control(const control&) = delete;
        control(control&&) = delete;

        auto operator=(const control&) -> control& = delete;
        auto operator=(control&&) -> control& = delete;

        ~control() override;

        virtual void set_parent_control(core::optional_reference<control>);
        auto get_parent_control() -> core::optional_reference<control>;
        auto get_parent_control() const -> core::const_optional_reference<control>;

        virtual void set_parent_window(core::optional_reference<window>);
        auto get_parent_window() -> core::optional_reference<window>;
        auto get_parent_window() const -> core::const_optional_reference<window>;

        CLSN_PROPERTY(actual_position, draw::point, true);
        CLSN_PROPERTY(actual_size, draw::dimension, true);

        CLSN_BOOL_PROPERTY_VAL(enabled, true, true);
        CLSN_BOOL_PROPERTY_VAL(visible, true, true);

        CLSN_PROPERTY(preferred_size, std::optional<clsn::draw::dimension>, true);

        auto get_actual_preferred_size() const -> const clsn::draw::dimension&;
        auto get_actual_bounds() const -> clsn::draw::region;

        auto operator==(const control&) const -> bool;
        auto operator!=(const control&) const -> bool;

        void add_mouse_click_listener(clsn::core::event_listener<events::mouse_click_event> event);
        void notify_mouse_click_event(events::mouse_click_event& e);

        void add_mouse_moved_listener(clsn::core::event_listener<events::mouse_moved_event> event);
        void notify_mouse_moved_event(events::mouse_moved_event& e);

        void paint(graphics& graphics, const clsn::draw::region& region) const;

        auto get_default_section_name() const -> std::string_view;

        template <typename TagType, typename... Args>
        void make_tag(Args&... args)
        {
            m_tag = std::make_unique<clsn::core::entity_wrapper<TagType>>(
                std::forward<Args>(args)...);
        }

        template <typename TagType>
        auto get_tag_or_default(const TagType& defValue) const -> const TagType&
        {
            if (m_tag == nullptr)
                return defValue;

            return static_cast<clsn::core::entity_wrapper<TagType>&>(*m_tag).get();
        }

        void set_renderer(std::unique_ptr<renderer_base>&& renderer) const;

        auto get_renderer() const -> const renderer_base&;
        auto get_renderer() -> renderer_base&;

        virtual void do_layout();

        virtual void invalidate() const noexcept;
        virtual void validate() const noexcept;
        virtual auto is_invalidated() const noexcept -> bool;

        virtual void release_mouse();

        auto is_hovered() const -> bool;

        auto contains_point(const clsn::draw::point& point) const -> bool;
        virtual auto get_control_by_position(const clsn::draw::point& point) const ->
                core::const_optional_reference<control>;

        template <typename Proc>
        void invoke_in_parent_window(Proc proc)
        {
            m_parent_window.safe_invoke(proc);
        }

        virtual void load_defaults();

        auto to_string() const -> std::string override;

    protected:
        virtual void process_mouse_click_event(events::mouse_click_event& e);
        virtual void process_mouse_moved_event(events::mouse_moved_event& e);

    private:
        [[nodiscard]] virtual auto make_default_renderer() const -> std::unique_ptr<renderer_base>;

        void init_control_events();

    public:
        template <typename T, typename... Args>
        static auto make(Args&&... args) -> std::shared_ptr<T>
        {
            return std::make_shared<T>(std::forward<Args>(args)...);
        }
    };

}