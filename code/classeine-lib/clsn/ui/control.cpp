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

#include <clsn/draw/Region.h>

namespace clsn::ui
{
    CLSN_CPP_PROPERTY(control, ActualPosition, draw::Point)
    CLSN_CPP_PROPERTY(control, ActualSize, draw::Dimension)

    CLSN_CPP_BOOL_PROPERTY(control, Enabled)
    CLSN_CPP_BOOL_PROPERTY(control, Visible)

    CLSN_CPP_PROPERTY(control, PreferredSize, std::optional<clsn::draw::Dimension>)

    control::control(std::string_view sectionName)
    : m_default_section_name{sectionName}
    , m_invalidated{true}
    {
        init_control_events();
    }

    control::~control() = default;

    void control::paint(graphics& graphics, const draw::Region& Region) const
    {
        debugCount("paint");

        if (!is_invalidated())
            return;

        get_renderer().paint(graphics, Region, *this);
    }

    void control::notify_mouse_click_event(events::mouse_click_event& e)
    {
        process_mouse_click_event(e);
    }

    void control::add_mouse_moved_listener(core::EventListener<events::mouse_moved_event> Event)
    {
        m_mouse_moved_listeners.add(std::move(Event));
    }

    void control::notify_mouse_moved_event(events::mouse_moved_event& e)
    {
        process_mouse_moved_event(e);
    }

    void control::process_mouse_click_event(events::mouse_click_event& e)
    {
        if (!isEnabled())
            return;

        if (e.get_status() == events::mouse_click_status::released)
        {
            invoke_in_parent_window([](auto& w) { w.release_mouse(); });
        }

        m_mouse_click_listeners.notify(e);
    }

    void control::process_mouse_moved_event(events::mouse_moved_event& e)
    {
        if (!isEnabled())
            return;

        m_mouse_moved_listeners.notify(e);
    }

    void control::add_mouse_click_listener(core::EventListener<events::mouse_click_event> Event)
    {
        m_mouse_click_listeners.add(std::move(Event));
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
        debugCount("do_layout");
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

        addVisibleChangedListener(invalidate_proc);
    }

    void control::set_parent_window(core::OptionalReference<window> parentWindow)
    {
        m_parent_window = parentWindow;
    }

    core::OptionalReference<window> control::get_parent_window()
    {
        return m_parent_window;
    }

    core::constOptionalReference<window>
        control::get_parent_window() const
    {
        return m_parent_window.to_const();
    }

    auto control::containsPoint(const draw::Point& Point) const -> bool
    {
        return draw::Region{m_propertyActualPosition.get(), m_propertyActualSize.get()}.containsPoint(Point);
    }

    auto control::get_control_by_position(const draw::Point& Point) const
        -> core::constOptionalReference<control>
    {
        if (this->containsPoint(Point))
            return *this;

        return std::nullopt;
    }

    auto control::is_hovered() const -> bool
    {
        if (!m_parent_window.hasValue())
            return false;

        return m_parent_window.getRef().is_hovered(*this);
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

    auto control::get_actual_preferred_size() const -> const draw::Dimension&
    {
        const auto& size = getPreferredSize();
        if (size.has_value())
            return size.value();

        return ui_manager::get_instance().get_dimension(m_default_section_name, "preferredSize");
    }

    auto control::get_actual_bounds() const -> draw::Region
    {
        return { getActualPosition(), getActualSize() };
    }

    void control::set_parent_control(core::OptionalReference<control> ctrl)
    {
        m_parent_control = ctrl;
    }

    auto control::get_parent_control() -> core::OptionalReference<control>
    {
        return m_parent_control;
    }

    auto control::get_parent_control() const -> core::constOptionalReference<control>
    {
        return m_parent_control.to_const();
    }

    auto control::toString() const -> std::string
    {
        using namespace clsn::core;
        return Strings::format("({}): {}", typeid(*this).name(), this);
    }
}