#pragma once

#include "Entity.h"

#include <utility>

namespace clsn::core
{
    template <typename Type>
    class EntityWrapper : public Entity
    {
        Type m_value;

    public:
        EntityWrapper(Type value)
        : m_value{std::move(value)}
        {
        }

        auto get() const noexcept -> const Type& { return m_value; }
        auto get() noexcept -> Type& { return m_value; }
    };
}