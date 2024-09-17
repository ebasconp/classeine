// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/control.h>

#include <clsn/ui/renderer_base.h>
#include <clsn/ui/ui_manager.h>
#include <clsn/ui/window.h>

#include <clsn/ui/events/mouse_click_event.h>
#include <clsn/ui/events/mouse_moved_event.h>

#include <clsn/ui/renderers/null_renderer.h>

#include <clsn/draw/region.h>

namespace clsn::ui
{
    control::control(std::string_view section_name)
    : m_default_section_name{section_name}
    , m_invalidated{true}
    {
        init_control_events();
    }

    control::~control() = default;

    void control::paint(graphics& graphics, const draw::region& region) const
    {
        debug_count("paint");

        if (!is_invalidated())
            return;

        get_renderer().paint(graphics, region, *this);
    }

    void control::notify_mouse_click_event(events::mouse_click_event& e)
    {
        process_mouse_click_event(e);
    }

    void control::add_mouse_moved_listener(core::event_listener<events::mouse_moved_event> event)
    {
        m_mouse_moved_listeners.add(std::move(event));
    }

    void control::notify_mouse_moved_event(events::mouse_moved_event& e)
    {
        process_mouse_moved_event(e);
    }

    void control::process_mouse_click_event(events::mouse_click_event& e)
    {
        if (!is_enabled())
            return;

        if (e.get_status() == events::mouse_click_status::released)
        {
            invoke_in_parent_window([](auto& w) { w.release_mouse(); });
        }

        m_mouse_click_listeners.notify(e);
    }

    void control::process_mouse_moved_event(events::mouse_moved_event& e)
    {
        if (!is_enabled())
            return;

        m_mouse_moved_listeners.notify(e);
    }

    void control::add_mouse_click_listener(core::event_listener<events::mouse_click_event> event)
    {
        m_mouse_click_listeners.add(std::move(event));
    }

    auto control::get_default_section_name() const -> std::string_view
    {
        return m_default_section_name;
    }

    void control::set_renderer(std::unique_ptr<renderer_base>&& renderer) const
    {
        m_renderer = std::move(renderer);
    }

    void control::do_layout()
    {
        debug_count("do_layout");
    }

    void control::invalidate() const noexcept { m_invalidated = true; }

    void control::validate() const noexcept { m_invalidated = false; }

    auto control::is_invalidated() const noexcept -> bool
    {
        return m_invalidated;
    }

    void control::release_mouse()
    {
        // Nothing to do here
    }

    auto control::operator==(const control& other) const -> bool
    {
        return this == &other;
    }


    auto control::operator!=(const control& other) const -> bool
    {
        return this != &other;
    }


    void control::init_control_events()
    {
        auto invalidate_proc = [this](auto&) { invalidate(); };

        add_visible_changed_listener(invalidate_proc);
    }

    void control::set_parent_window(optional_reference<window> parentWindow)
    {
        m_parent_window = parentWindow;
    }

    optional_reference<window> control::get_parent_window()
    {
        return m_parent_window;
    }

    optional_reference<const window>
        control::get_parent_window() const
    {
        return m_parent_window;
    }

    auto control::contains_point(const draw::point& point) const -> bool
    {
        return draw::region{m_actual_position.get(), m_actual_size.get()}.contains_point(point);
    }

    auto control::get_control_by_position(const draw::point& point) const
        -> std::optional<std::reference_wrapper<const control>>
    {
        if (this->contains_point(point))
            return *this;

        return std::nullopt;
    }

    auto control::is_hovered() const -> bool
    {
        if (!m_parent_window.has_value())
            return false;

        return m_parent_window.value().get().is_hovered(*this);
    }


    auto control::make_default_renderer() const -> std::unique_ptr<renderer_base>
    {
        return std::make_unique<renderers::null_renderer>();
    }

    auto control::get_renderer() -> renderer_base&
    {
        if (m_renderer == nullptr)
            m_renderer = std::move(make_default_renderer());

        return *m_renderer;
    }

    auto control::get_renderer() const -> const renderer_base&
    {
        if (m_renderer == nullptr)
            m_renderer = std::move(make_default_renderer());

        return *m_renderer;
    }

    void control::load_defaults()
    {
        // Do nothing here
    }

    auto control::get_actual_preferred_size() const -> const draw::dimension&
    {
        const auto& size = get_preferred_size();
        if (size.has_value())
            return size.value();

        return ui_manager::get_instance().get_dimension(m_default_section_name, "preferredSize");
    }

    auto control::get_actual_bounds() const -> draw::region
    {
        return { get_actual_position(), get_actual_size() };
    }

    void control::set_parent_control(std::optional<std::reference_wrapper<control>> ctrl)
    {
        m_parent_control = ctrl;
    }

    auto control::get_parent_control() -> optional_reference<control>
    {
        return m_parent_control;
    }

    auto control::get_parent_control() const -> const_optional_reference<control>
    {
        return m_parent_control;
    }

    auto control::to_string() const -> std::string
    {
        using namespace clsn::core::strings;
        return format("({}): {}", typeid(*this).name(), this);
    }
}