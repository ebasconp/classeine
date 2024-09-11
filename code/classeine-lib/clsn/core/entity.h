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
    class entity
    {
#ifdef _CLSN_DEBUG_
        static std::atomic<int> m_instances_created;
        static std::atomic<int> m_instances_destroyed;
        static std::unordered_set<entity*> m_living_entities;
        static std::unordered_map<std::string, int> m_counters;
#endif
    public:
        entity();
        entity(const entity&);
        entity(entity&&) noexcept;

        void debug_count(std::string_view key) const;

        virtual ~entity();

        virtual auto to_string() const -> std::string;

        static void dump();
    };
}