#pragma once

#include "clsn/ui/control.h"

#include "clsn/core/empty_event.h"
#include "clsn/core/event_listener_list.h"

namespace clsn::ui
{
    class clickable_control : public control
    {
        bool m_pressed = false;
        event_listener_list<empty_event> m_action_listeners;

    public:
        explicit clickable_control(std::string_view section_name);

        [[nodiscard]] auto is_pressed() const noexcept -> bool;

        void add_action_listener(event_listener<empty_event> event);
        void notify_action_event(empty_event& e);

        void release_mouse() override;

    protected:
        void process_mouse_click_event(events::mouse_click_event& e) override;

    private:
        void init_events();
    };
}