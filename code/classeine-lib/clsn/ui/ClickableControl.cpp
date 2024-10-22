// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/ClickableControl.h>
#include <clsn/ui/Window.h>

namespace clsn::ui
{
    CLSN_CPP_PROPERTY(ClickableControl, ActionName, std::string)

    ClickableControl::ClickableControl(std::string_view sectionName)
    : CaptionableControl{sectionName}
    {
        initClickableControlEvents();
    }

    [[nodiscard]] auto ClickableControl::isPressed() const noexcept -> bool
    {
        return m_pressed;
    }

    void ClickableControl::addActionListener(clsn::core::EventListener<events::ActionEvent> Event)
    {
        m_action_listeners.add(std::move(Event));
    }

    void ClickableControl::notifyActionEvent(events::ActionEvent& e)
    {
        m_action_listeners.notify(e);
    }

    void ClickableControl::releaseMouse()
    {
        m_pressed = false;
        invalidate();
    }

    void ClickableControl::initClickableControlEvents()
    {
        addCaptionChangedListener([this](auto&) { invalidate(); });
    }

    void ClickableControl::processMouseClickEvent(events::MouseClickEvent& e)
    {
        auto pressed_now = e.getStatus() == clsn::ui::events::MouseClickStatus::pressed;

        m_pressed = pressed_now;
        this->invalidate();

        if (!m_pressed) // Button has been released, then Action
        {
            events::ActionEvent _action_event{*this, m_propertyActionName.get()};
            notifyActionEvent(_action_event);
        }
        else
        {
            invokeInParentWindow([this](auto& parentWindow)
            {
                parentWindow.grabMouse(*this);
            });
        }

        Control::processMouseClickEvent(e);
    }
}