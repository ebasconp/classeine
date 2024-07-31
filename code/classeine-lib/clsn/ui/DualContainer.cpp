#include "DualContainer.h"

#include "clsn/core/Panic.h"

namespace clsn::ui
{
    DualContainer::DualContainer()
    : ListContainer<DualContainerConstraint>{"DualContainer"}
    , m_orientation{DualContainerOrientation::horizontal}
    {
    }


    auto DualContainer::getOrientation() const -> DualContainerOrientation
    {
        return m_orientation;
    }


    void DualContainer::setOrientation(DualContainerOrientation orientation)
    {
        m_orientation = orientation;
    }


    void DualContainer::checkIfValidBeforeAdding(const DualContainerConstraint& constraint) const
    {
        if (getCount() == 2)
            Panic("Dual container can only contain two elements");

        if (getCount() == 1 && constraint == getConstraintAt(0))
            Panic("Both controls must have different constraints");
    }


    void DualContainer::doLayout()
    {
        const auto visibleCount = getVisibleCount();
        if (visibleCount == 0)
            return;

        const auto position = getActualPosition();
        const auto size = getActualSize();

        const auto count = getCount();
        if (count == 1)
        {
            auto& cc = getControlAndConstraintAt(0);

            auto ch = cc.constraint
                ? size.getHeight() : cc.control->getActualSize().getHeight();

            cc.control->setActualSize({size.getWidth(), ch});
            cc.control->setActualPosition({0, 0});
        }
        else if (count == 2)
        {
            auto& cc0 = getControlAndConstraintAt(0);
            auto& cc1 = getControlAndConstraintAt(1);

            auto c0h = cc0.constraint == DualContainerConstraint::use_all_available_space
                            ? size.getHeight() - cc1.control->getActualPreferredSize().getHeight()
                            : cc0.control->getActualPreferredSize().getHeight();

            auto c1h = size.getHeight() - c0h;

            cc0.control->setActualSize({size.getWidth(), c0h});
            cc1.control->setActualSize({size.getWidth(), c1h});

            cc0.control->setActualPosition(position);
            cc1.control->setActualPosition({position.getX(), position.getY() + c0h});
        }
    }
}