#include "Entity.h"

namespace clsn::core
{
#ifdef _CLSN_DEBUG_
    inline std::atomic<int> Entity::m_instancesCreated{0};
    inline std::atomic<int> Entity::m_instancesDestroyed{0};
    inline std::unordered_set<Entity*> Entity::m_livingEntities;
#endif

    Entity::Entity()
    {
#ifdef _CLSN_DEBUG_
        m_instancesCreated++;
        m_livingEntities.insert(this);
#endif
    }

    Entity::~Entity()
    {
#ifdef _CLSN_DEBUG_
        m_instancesDestroyed++;
        m_livingEntities.erase(this);
#endif
    }

    void Entity::dump()
    {
#ifdef _CLSN_DEBUG_
        std::cout << "Classeine number of instances created:   " << m_instancesCreated << std::endl;
        std::cout << "Classeine number of instances destroyed: " << m_instancesDestroyed << std::endl;
        std::cout << "************************************************************************\n";
        std::cout << "Living entities:\n";
        for (auto p : m_livingEntities)
        {
            std::cout << "* (" << typeid(*p).name() << ")\n";
        }
#endif
    }
}
