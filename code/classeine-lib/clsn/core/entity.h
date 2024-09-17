// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#ifdef _CLSN_DEBUG_
#include <atomic>
#include <string>
#include <unordered_map>
#include <unordered_set>
#endif

#include <string_view>

/// This namespace contains several basic utilities and base classes that
/// make developing applications with *classeine* easier.
///
/// Configuration utilities, console methods, events, properties, and string
/// handling utilities are available here.
namespace clsn::core
{
    /// This is the base class for all polymorphic class hierarchies.
    ///
    /// In addition to providing a base for polymorphic use within containers,
    /// it exposes a `to_string()` method and, in debug mode, stores information
    /// about objects being instantiated and deallocated.
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