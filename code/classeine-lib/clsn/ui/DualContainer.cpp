#include "DualContainer.h"

#include "clsn/core/Panic.h"

namespace clsn::ui
{
    DualContainer::DualContainer()
    : ListContainer<bool>{"DualContainer"}
    , m_horizontal{true}
    {
    }


    auto DualContainer::isHorizontal() const -> bool
    {
        return m_horizontal;
    }


    void DualContainer::setHorizontal(bool horizontal)
    {
        m_horizontal = horizontal;
    }


    void DualContainer::checkIfValid(const bool& fill) const
    {
        if (getCount() == 2)
            Panic("Dual container can only contain two elements");

        if (getCount() == 1 && fill == getConstraintAt(0))
            Panic("Both controls must have different constraints");
    }
}