// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "clsn/ui/captionable_control.h"

#include "clsn/ui/events/action_event.h"

#include "clsn/core/event_listener_list.h"

namespace clsn::ui
{
    /// Base class for all clickable controls (buttons, checkboxes, radio buttons, etc.):
    ///
    /// It provides functionality for handling clickable controls and also
    /// exposes the action event and action name for handling clicks.
    class clickable_control : public captionable_control
    {
        bool m_pressed = false;
        clsn::core::event_listener_list<events::action_event> m_action_listeners;

    public:
        explicit clickable_control(std::string_view section_name);

        CLSN_PROPERTY(action_name, std::string, true)

        [[nodiscard]] auto is_pressed() const noexcept -> bool;

        void add_action_listener(clsn::core::event_listener<events::action_event> event);
        void notify_action_event(events::action_event& e);

        void release_mouse() override;

    protected:
        void process_mouse_click_event(events::mouse_click_event& e) override;

    private:
        void init_clickable_control_events();
    };
}