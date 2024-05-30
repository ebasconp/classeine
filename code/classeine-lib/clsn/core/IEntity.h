#pragma once

namespace clsn::core
{
    // Base class for polymorphic containers

    class IEntity
    {
    public:
        virtual ~IEntity() = default;
    };
}