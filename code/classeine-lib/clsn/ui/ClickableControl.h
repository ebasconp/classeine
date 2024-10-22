// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/CaptionableControl.h>

#include <clsn/ui/events/ActionEvent.h>

#include <clsn/core/EventListenerList.h>

namespace clsn::ui
{
    /// Base class for all clickable controls (buttons, checkboxes, radio buttons, etc.):
    ///
    /// It provides functionality for handling clickable controls and also
    /// exposes the action Event and action name for handling clicks.
    class ClickableControl : public CaptionableControl
    {
        bool m_pressed = false;
        clsn::core::EventListenerList<events::ActionEvent> m_action_listeners;

    public:
        explicit ClickableControl(std::string_view sectionName);

        CLSN_HEADER_PROPERTY(ActionName, std::string, true)

        [[nodiscard]] auto isPressed() const noexcept -> bool;

        void addActionListener(clsn::core::EventListener<events::ActionEvent> Event);
        void notifyActionEvent(events::ActionEvent& e);

        void releaseMouse() override;

    protected:
        void processMouseClickEvent(events::MouseClickEvent& e) override;

    private:
        void initClickableControlEvents();
    };
}