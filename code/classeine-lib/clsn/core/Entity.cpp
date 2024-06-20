#include "Entity.h"

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

    void Entity::debug_count(std::string_view key) const
    {
#ifdef _CLSN_DEBUG_
        m_counters[std::string{key}]++;
#endif
    }

    void Entity::dump()
    {
#ifdef _CLSN_DEBUG_
        auto instancesLeftCount = m_instancesCreated - m_instancesDestroyed;
        std::cout
            << "*********************************************************\n"
            << "Classeine number of instances left:   "
            << instancesLeftCount << std::endl
            << "*********************************************************\n";

        if (instancesLeftCount != 0)
        {
            std::cout << "Living entities:\n";

            for (auto& p : m_livingEntities)
            {
                std::cout << "* (" << typeid(*p).name() << ")\n";
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
