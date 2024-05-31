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

        auto get() const noexcept -> const Type& { return m_value; }
        auto get() noexcept -> Type& { return m_value; }
    };
}