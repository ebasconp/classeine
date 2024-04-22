#pragma once

#include "EventListener.h"
#include "EventListenerHandle.h"

#include <vector>

namespace clsn::core
{
    template <typename EventType>
    class EventListenerList
    {
        struct EventListenerContainer
        {
            EventListener<EventType> callback;
            bool enabled;
        };

        std::vector<EventListenerContainer> m_listeners;

    public:
        EventListenerHandle add(EventListener<EventType> callback)
        {
            m_listeners.emplace_back(callback, true);

            return m_listeners.size() - 1;
        }

        void notify(EventType& e)
        {
            for (auto& listener : m_listeners)
            {
                if (e.isConsumed())
                    break;

                if (!listener.enabled)
                    continue;

                listener.callback(e);
            }
        }

        void setEnabled(EventListenerHandle eventHandle, bool enabled)
        {
            m_listeners[eventHandle].enabled = enabled;
        }

        void clear() { m_listeners.clear(); }
    };
}