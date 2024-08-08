#include "ClickableControl.h"
#include "Window.h"


namespace clsn::ui
{
    ClickableControl::ClickableControl(std::string_view section_name)
    : Control{section_name}
    {
        initEvents();
    }

    [[nodiscard]] auto ClickableControl::isPressed() const noexcept -> bool
    {
        return m_pressed;
    }

    void ClickableControl::add_action_listener(event_listener<empty_event> event)
    {
        m_actionListeners.add(std::move(event));
    }

    void ClickableControl::notifyActionEvent(empty_event& e)
    {
        m_actionListeners.notify(e);
    }

    void ClickableControl::releaseMouse()
    {
        m_pressed = false;
        invalidate();
    }

    void ClickableControl::initEvents()
    {
        add_text_changed_listener([this](auto&) { invalidate(); });
    }

    void ClickableControl::processMouseClickEvent(events::MouseClickEvent& e)
    {
        auto pressedNow = e.getStatus() == clsn::ui::events::MouseClickStatus::pressed;

        m_pressed = pressedNow;
        this->invalidate();

        if (!m_pressed) // Button has been released, then Action
        {
            empty_event actionEvent;
            notifyActionEvent(actionEvent);
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