#pragma once

#include <atomic>
#include <iostream>

namespace clsn::core
{
    // Base class for polymorphic containers
    class IEntity
    {
        static std::atomic<int> m_instanceCount;

    public:
        IEntity()
        {
            m_instanceCount++;
            std::cout << "INSTANCE COUNT: " << m_instanceCount << std::endl;
        }

        virtual ~IEntity()
        {
            m_instanceCount--;
        }

        static void dump()
        {
            std::cout << "Classeine final instance count: " << m_instanceCount << std::endl;
        }
    };

    inline std::atomic<int> IEntity::m_instanceCount{0};
}