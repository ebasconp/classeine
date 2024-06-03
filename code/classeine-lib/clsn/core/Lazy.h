#pragma once

#include "Entity.h"

#include <functional>
#include <optional>

namespace clsn::core
{
    template <typename T>
    class Lazy final : public Entity
    {
        mutable std::optional<T> m_instance;
        std::function<T ()> m_factory;

    public:
        explicit Lazy(std::function<T()> factory)
        : m_factory{factory}
        {
        }

        // C++23
        /*template <typename Self>
        auto& get(this Self&& self)
        {
            auto& t = std::forward<Self>(self);
            if (!t.m_instance.has_value())
                t.m_instance = t.m_factory();

            return t.m_instance.value();
        }*/

        const auto& get() const
        {
            if (!m_instance.has_value())
                m_instance = m_factory();

            return m_instance.value();
        }

        auto& get()
        {
            if (!m_instance.has_value())
                m_instance = m_factory();

            return m_instance.value();
        }
    };
}