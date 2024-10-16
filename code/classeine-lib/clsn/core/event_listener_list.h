// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/core/event_listener.h>

#include <vector>

namespace clsn::core
{
    template <typename EventType>
    class event_listener_list
    {
        struct event_listener_container
        {
            event_listener<EventType> callback;
            bool enabled;
        };

        std::vector<event_listener_container> m_listeners;

    public:
        auto add(event_listener<EventType> callback) -> int
        {
            m_listeners.emplace_back(callback, true);

            return static_cast<int>(m_listeners.size()) - 1;
        }

        void notify(EventType& e)
        {
            for (auto& listener : m_listeners)
            {
                if (e.is_consumed())
                    break;

                if (!listener.enabled)
                    continue;

                listener.callback(e);
            }
        }

        void set_enabled(int index, bool enabled)
        {
            m_listeners[index].enabled = enabled;
        }

        void clear() { m_listeners.clear(); }
    };
}