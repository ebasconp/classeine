#pragma once

#include <functional>
#include <memory>

namespace clsn::core
{
    template <typename BaseType>
    class Factory
    {
        std::function<std::unique_ptr<BaseType>()> m_factory;

    public:
        template <typename DerivedType>
        Factory& set()
        {
            m_factory = []() { return std::make_unique<DerivedType>(); };
            return *this;
        }

        std::unique_ptr<BaseType> operator()() const
        {
            return m_factory();
        }
    };


    template <typename BaseType, typename DerivedType>
    Factory<BaseType> makeFactory()
    {
        auto factory = Factory<BaseType>{};
        return factory.template set<DerivedType>();
    }
}