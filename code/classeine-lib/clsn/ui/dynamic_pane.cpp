// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "dynamic_pane.h"

#include "renderers/dynamic_pane_renderer.h"

#include <clsn/core/console.h>

namespace clsn::ui
{
    using namespace clsn::draw;
    using namespace clsn::ui::renderers;

    dynamic_pane::dynamic_pane() : control("dynamic_pane")
    {
        init_dynamic_pane_events();
    }

    void dynamic_pane::do_layout()
    {
        if (m_inner_control == nullptr)
            return;

        m_inner_control->set_actual_position(this->get_actual_position());
        m_inner_control->set_actual_size(this->get_actual_size());
        m_inner_control->do_layout();
    }

    auto dynamic_pane::make_default_renderer() const -> std::unique_ptr<renderer_base>
    {
        return std::make_unique<dynamic_pane_renderer>();
    }

    auto dynamic_pane::get_inner_control() -> std::shared_ptr<control>&
    {
        return m_inner_control;
    }

    auto dynamic_pane::get_inner_control() const -> const std::shared_ptr<control>&
    {
        return m_inner_control;
    }

    void dynamic_pane::set_inner_control(const std::shared_ptr<control>& ctrl)
    {
        if (m_inner_control.get() == ctrl.get())
            return;

        if (m_inner_control != nullptr)
        {
            m_inner_control->set_parent_control(std::nullopt);
            m_inner_control->set_parent_window(std::nullopt);
        }

        m_inner_control = ctrl;

        if (ctrl != nullptr)
        {
            m_inner_control->set_parent_window(this->get_parent_window());
            m_inner_control->set_parent_control(*this);
        }

        do_layout();
        invalidate();
    }

    void dynamic_pane::invalidate() const noexcept
    {
        //ETOTODO: clsn::core::console::debug("dynamic_pane::invalidate: [[{}]]", *this);
        control::invalidate();

        if (m_inner_control != nullptr)
            m_inner_control->invalidate();
    }

    void dynamic_pane::validate() const noexcept
    {
        control::validate();

        if (m_inner_control != nullptr)
            m_inner_control->validate();
    }

    auto dynamic_pane::is_invalidated() const noexcept -> bool
    {
        if (m_inner_control == nullptr)
        {
            return control::is_invalidated();
        }

        return m_inner_control->is_invalidated();
    }

    void dynamic_pane::process_mouse_click_event(events::mouse_click_event& e)
    {
        if (m_inner_control == nullptr)
            return;

        if (!m_inner_control->is_visible() || !m_inner_control->is_enabled())
                return;

        if (m_inner_control->contains_point(e.get_point()))
        {
            m_inner_control->notify_mouse_click_event(e);
        }

        control::process_mouse_click_event(e);
    }

    void dynamic_pane::process_mouse_moved_event(events::mouse_moved_event& e)
    {
        control::process_mouse_moved_event(e);

        if (m_inner_control == nullptr)
            return;

        if (!m_inner_control->is_visible() || !m_inner_control->is_enabled())
            return;

        if (m_inner_control->contains_point(e.get_position()))
        {
            m_inner_control->notify_mouse_moved_event(e);
        }
    }

    void dynamic_pane::init_dynamic_pane_events()
    {
        add_actual_size_changed_listener([this](auto& )
        {
            do_layout();
        });
    }

    auto dynamic_pane::get_control_by_position(const point &point) const
            -> const_optional_reference<control>
    {
        if (m_inner_control == nullptr)
            return {};

        if (!m_inner_control->is_visible() || !m_inner_control->is_enabled())
            return {};

        return m_inner_control->get_control_by_position(point);
    }
}