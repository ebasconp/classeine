#pragma once

#include <atomic>
#include <iostream>
#include <unordered_set>

namespace clsn::core
{
    // Base class for polymorphic containers
    class Entity
    {
#ifdef _CLSN_DEBUG_
        static std::atomic<int> m_instancesCreated;
        static std::atomic<int> m_instancesDestroyed;
        static std::unordered_set<Entity*> m_livingEntities;
#endif
    public:
        Entity();
        virtual ~Entity();

        static void dump();
    };
}