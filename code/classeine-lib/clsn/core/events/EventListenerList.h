#pragma once

#include "EventListenerHandle.h"

#include <functional>
#include <vector>


namespace clsn::core::events
{
    template <typename TEventListener>
    class EventListenerList
    {
        std::unordered_map<int, std::pair<TEventListener, bool>> m_listeners;
        EventListenerHandle nextId = 0;

    public:
        template <typename T>
        EventListenerHandle add(const T& func)
        {
            m_listeners[nextId] = std::make_pair(func, true);
            return nextId++;
        }

        void setEnabled(EventListenerHandle handle, bool enabled)
        {
            auto it = m_listeners.find(handle);
            if (it == m_listeners.end())
                return;

            it->second.second = enabled;
        }

        template <typename... TArgs>
        void operator()(TArgs&&... args)
        {
            for (auto& listener : m_listeners)
                if (listener.second.second)
                    listener.second.first(std::forward<TArgs>(args)...);
        }
    };
}