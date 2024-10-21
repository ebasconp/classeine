// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/captionable_control.h>

#include <clsn/ui/events/action_event.h>

#include <clsn/core/EventListenerList.h>

namespace clsn::ui
{
    /// Base class for all clickable controls (buttons, checkboxes, radio buttons, etc.):
    ///
    /// It provides functionality for handling clickable controls and also
    /// exposes the action Event and action name for handling clicks.
    class clickable_control : public captionable_control
    {
        bool m_pressed = false;
        clsn::core::EventListenerList<events::action_event> m_action_listeners;

    public:
        explicit clickable_control(std::string_view sectionName);

        CLSN_HEADER_PROPERTY(ActionName, std::string, true)

        [[nodiscard]] auto is_pressed() const noexcept -> bool;

        void add_action_listener(clsn::core::EventListener<events::action_event> Event);
        void notify_action_event(events::action_event& e);

        void release_mouse() override;

    protected:
        void process_mouse_click_event(events::mouse_click_event& e) override;

    private:
        void init_clickable_control_events();
    };
}