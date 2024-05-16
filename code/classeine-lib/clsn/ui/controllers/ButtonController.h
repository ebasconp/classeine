#pragma once

#include "clsn/core/EmptyEvent.h"
#include "clsn/core/EventListenerList.h"

#include <string_view>

namespace clsn::ui::controllers
{
    using namespace clsn::core;

    class ButtonController
    {
    private:
        EventListenerList<EmptyEvent> m_actionListeners;

    public:
        [[nodiscard]] std::string_view getDefaultSectionName() const
        {
            return "Button";
        }

        void addActionListener(EventListener<EmptyEvent> event)
        {
            m_actionListeners.add(std::move(event));
        }

        void notifyActionEvent(EmptyEvent& e)
        {
            m_actionListeners.notify(e);
        }
    };
}