#pragma once

#include "entity.h"

#include <functional>
#include <optional>

namespace clsn::core
{
    template <typename T>
    class Lazy final : public entity
    {
        mutable std::optional<T> m_instance;
        std::function<T ()> m_factory;

    public:
        explicit Lazy(std::function<T()> factory)
        : m_factory{factory}
        {
        }

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