#pragma once

#include "clsn/core/EmptyEvent.h"
#include "clsn/core/EventListenerList.h"

namespace clsn::ui::events
{
    using namespace clsn::core;

    class ActionEventManager
    {
    private:
        EventListenerList<EmptyEvent> m_actionListeners;

    public:
        void addActionListener(EventListener<EmptyEvent> event)
        {
            m_actionListeners.add(event);
        }

        void notifyActionEvent(EmptyEvent& e)
        {
            m_actionListeners.notify(e);
        }
    };
}