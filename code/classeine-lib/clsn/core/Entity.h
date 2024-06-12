#pragma once

#include <atomic>
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
        Entity(const Entity&);
        Entity(Entity&&) noexcept;

        virtual ~Entity();

        static void dump();
    };
}