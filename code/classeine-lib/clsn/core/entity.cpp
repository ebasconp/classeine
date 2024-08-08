#include "entity.h"

#include <iostream>

namespace clsn::core
{
#ifdef _CLSN_DEBUG_
    inline std::atomic<int> entity::m_instances_created{0};
    inline std::atomic<int> entity::m_instances_destroyed{0};
    inline std::unordered_set<entity*> entity::m_living_entities;
    inline std::unordered_map<std::string, int> entity::m_counters;
#endif

    entity::entity()
    {
#ifdef _CLSN_DEBUG_
        ++m_instances_created;
        m_living_entities.insert(this);
#endif
    }

    entity::entity(const entity&)
    {
#ifdef _CLSN_DEBUG_
        ++m_instances_created;
        m_living_entities.insert(this);
#endif
    }

    entity::entity(entity&&) noexcept
    {
#ifdef _CLSN_DEBUG_
        ++m_instances_created;
        m_living_entities.insert(this);
#endif
    }

    entity::~entity()
    {
#ifdef _CLSN_DEBUG_
        ++m_instances_destroyed;
        m_living_entities.erase(this);
#endif
    }

    void entity::debug_count(std::string_view key) const
    {
#ifdef _CLSN_DEBUG_
        m_counters[std::string{key}]++;
#endif
    }

    void entity::dump()
    {
#ifdef _CLSN_DEBUG_
        auto instances_left_count = m_instances_created - m_instances_destroyed;
        std::cout
            << "*********************************************************\n"
            << "Classeine number of instances left:   "
            << instances_left_count << std::endl
            << "*********************************************************\n";

        if (instances_left_count != 0)
        {
            std::cout << "Living entities:\n";

            for (auto& p : m_living_entities)
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
