#pragma once

#include "IEntity.h"

#include <utility>

namespace clsn::core
{
    template <typename Type>
    class Entity : public IEntity
    {
        Type m_value;

    public:
        Entity(Type value)
        : m_value{std::move(value)}
        {
        }

        const Type& get() const noexcept { return m_value; }
        Type& get() noexcept { return m_value; }
    };
}