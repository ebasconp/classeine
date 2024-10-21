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
/// Configuration utilities, Console methods, events, properties, and string
/// handling utilities are available here.
namespace clsn::core
{
    /// This is the base class for all polymorphic class hierarchies.
    ///
    /// In addition to providing a base for polymorphic use within containers,
    /// it exposes a `toString()` method and, in debug mode, stores information
    /// about objects being instantiated and deallocated.
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

        void debugCount(std::string_view key) const;

        virtual ~Entity();

        [[nodiscard]] virtual auto toString() const -> std::string;

        static void dump();
    };
}