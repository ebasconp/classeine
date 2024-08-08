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

    void clickable_control::add_action_listener(event_listener<empty_event> event)
    {
        m_action_listeners.add(std::move(event));
    }

    void clickable_control::notify_action_event(empty_event& e)
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
        auto pressedNow = e.getStatus() == clsn::ui::events::mouse_click_status::pressed;

        m_pressed = pressedNow;
        this->invalidate();

        if (!m_pressed) // button has been released, then Action
        {
            empty_event actionEvent;
            notify_action_event(actionEvent);
        }
        else
        {
            invoke_in_parent_window([this](auto& parentWindow)
            {
                parentWindow.grabMouse(*this);
            });
        }

        control::process_mouse_click_event(e);
    }
}