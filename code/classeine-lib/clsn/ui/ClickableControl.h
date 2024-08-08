#pragma once

#include "clsn/ui/Control.h"

#include "clsn/core/empty_event.h"
#include "clsn/core/event_listener_list.h"

namespace clsn::ui
{
    class ClickableControl : public Control
    {
        bool m_pressed = false;
        event_listener_list<empty_event> m_actionListeners;

    public:
        explicit ClickableControl(std::string_view section_name);

        [[nodiscard]] auto isPressed() const noexcept -> bool;

        void add_action_listener(event_listener<empty_event> event);
        void notifyActionEvent(empty_event& e);

        void releaseMouse() override;

    protected:
        void processMouseClickEvent(events::MouseClickEvent& e) override;

    private:
        void initEvents();
    };
}