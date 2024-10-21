// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/core/Entity.h>

#include <clsn/core/Console.h>

#include <iostream>

namespace clsn::core
{
#ifdef _CLSN_DEBUG_
    inline std::atomic<int> Entity::m_instancesCreated{0};
    inline std::atomic<int> Entity::m_instancesDestroyed{0};
    inline std::unordered_set<Entity*> Entity::m_livingEntities;
    inline std::unordered_map<std::string, int> Entity::m_counters;
#endif

    Entity::Entity()
    {
#ifdef _CLSN_DEBUG_
        ++m_instancesCreated;
        m_livingEntities.insert(this);
#endif
    }

    Entity::Entity(const Entity&)
    {
#ifdef _CLSN_DEBUG_
        ++m_instancesCreated;
        m_livingEntities.insert(this);
#endif
    }

    Entity::Entity(Entity&&) noexcept
    {
#ifdef _CLSN_DEBUG_
        ++m_instancesCreated;
        m_livingEntities.insert(this);
#endif
    }

    Entity::~Entity()
    {
#ifdef _CLSN_DEBUG_
        ++m_instancesDestroyed;
        m_livingEntities.erase(this);
#endif
    }

    void Entity::debugCount(std::string_view key) const
    {
#ifdef _CLSN_DEBUG_
        m_counters[std::string{key}]++;
#endif
    }

    auto Entity::toString() const -> std::string
    {
        return clsn::core::Strings::format("({}): {}", typeid(*this).name(), this);
    }

    void Entity::dump()
    {
#ifdef _CLSN_DEBUG_
        auto instances_left_count = m_instancesCreated - m_instancesDestroyed;
        std::cout
            << "*********************************************************\n"
            << "Classeine number of instances left:   "
            << instances_left_count << std::endl
            << "*********************************************************\n";

        if (instances_left_count != 0)
        {
            clsn::core::Console::debug("Living entities");

            for (auto& p : m_livingEntities)
            {
                clsn::core::Console::debug("* {}", *p);
            }
        }

        if (!m_counters.empty())
        {
            std::cout
                << "*********************************************************\n"
                << "Counters:\n";

            for (auto& p : m_counters)
            {
                std::cout << "* [" << p.first << "]: " << p.second << "\n";
            }
        }
#endif
    }
}
