// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "clickable_control.h"
#include "window.h"


namespace clsn::ui
{
    clickable_control::clickable_control(std::string_view section_name)
    : control{section_name}
    {
        init_events();
    }

    [[nodiscard]] auto clickable_control::is_pressed() const noexcept -> bool
    {
        return m_pressed;
    }

    void clickable_control::add_action_listener(event_listener<action_event> event)
    {
        m_action_listeners.add(std::move(event));
    }

    void clickable_control::notify_action_event(action_event& e)
    {
        m_action_listeners.notify(e);
    }

    void clickable_control::release_mouse()
    {
        m_pressed = false;
        invalidate();
    }

    void clickable_control::init_events()
    {
        add_text_changed_listener([this](auto&) { invalidate(); });
    }

    void clickable_control::process_mouse_click_event(events::mouse_click_event& e)
    {
        auto pressed_now = e.get_status() == clsn::ui::events::mouse_click_status::pressed;

        m_pressed = pressed_now;
        this->invalidate();

        if (!m_pressed) // button has been released, then Action
        {
            action_event _action_event{*this, m_action_name.get()};
            notify_action_event(_action_event);
        }
        else
        {
            invoke_in_parent_window([this](auto& parent_window)
            {
                parent_window.grab_mouse(*this);
            });
        }

        control::process_mouse_click_event(e);
    }
}