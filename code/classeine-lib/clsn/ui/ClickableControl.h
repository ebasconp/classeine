#pragma once

#include "clsn/ui/Control.h"

#include "clsn/core/EmptyEvent.h"
#include "clsn/core/EventListenerList.h"


namespace clsn::ui
{
    class ClickableControl : public Control
    {
        bool m_pressed = false;
        EventListenerList<EmptyEvent> m_actionListeners;

    public:
        ClickableControl(std::string_view sectionName);

        [[nodiscard]] auto isPressed() const noexcept -> bool;

        void addActionListener(EventListener<EmptyEvent> event);
        void notifyActionEvent(EmptyEvent& e);

    private:
        void initEvents();
    };
}