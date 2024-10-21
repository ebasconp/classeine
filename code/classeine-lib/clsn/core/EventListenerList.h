// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/core/EventListener.h>

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
        auto add(EventListener<EventType> callback) -> int
        {
            m_listeners.emplace_back(callback, true);

            return static_cast<int>(m_listeners.size()) - 1;
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

        void setEnabled(int index, bool enabled)
        {
            m_listeners[index].enabled = enabled;
        }

        void clear() { m_listeners.clear(); }
    };
}