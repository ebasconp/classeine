#pragma once

#ifdef _CLSN_DEBUG_
#include <atomic>
#include <string>
#include <unordered_map>
#include <unordered_set>
#endif

#include <string_view>

namespace clsn::core
{
    // Base class for polymorphic containers
    class Entity
    {
#ifdef _CLSN_DEBUG_
        static std::atomic<int> m_instancesCreated;
        static std::atomic<int> m_instancesDestroyed;
        static std::unordered_set<Entity*> m_livingEntities;
        static std::unordered_map<std::string, int> m_counters;
#endif
    public:
        Entity();
        Entity(const Entity&);
        Entity(Entity&&) noexcept;

        void debug_count(std::string_view key) const;

        virtual ~Entity();

        static void dump();
    };
}