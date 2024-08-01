#include "DualContainer.h"

#include "clsn/core/Panic.h"

namespace clsn::ui
{
    DualContainer::DualContainer()
    : ListContainer<DualContainerConstraint>{"DualContainer"}
    , m_orientation{DualContainerOrientation::vertical}
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

        const auto& position = getActualPosition();
        const auto& size = getActualSize();

        switch (m_orientation)
        {
            case DualContainerOrientation::horizontal:
                doLayoutHorizontal(position, size);
                break;

            case DualContainerOrientation::vertical:
                doLayoutVertical(position, size);
                break;
        }
    }

    void DualContainer::doLayoutVertical(const Point& position, const Dimension& size)
    {
        const auto count = getCount();
        if (count == 1)
        {
            auto& cc = getControlAndConstraintAt(0);

            auto ch = cc.constraint == DualContainerConstraint::use_all_available_space
                ? size.getHeight()
                : cc.control->getActualPreferredSize().getHeight();

            cc.control->setActualSize({size.getWidth(), ch});
            cc.control->setActualPosition(position);
            return;
        }

        if (count == 2)
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


    void DualContainer::doLayoutHorizontal(const Point& position, const Dimension& size)
    {
        const auto count = getCount();
        if (count == 1)
        {
            auto& cc = getControlAndConstraintAt(0);

            auto cw = cc.constraint == DualContainerConstraint::use_all_available_space
                ? size.getWidth()
                : cc.control->getActualPreferredSize().getWidth();

            cc.control->setActualSize({cw, size.getHeight()});
            cc.control->setActualPosition(position);
            return;
        }

        if (count == 2)
        {
            auto& cc0 = getControlAndConstraintAt(0);
            auto& cc1 = getControlAndConstraintAt(1);

            auto c0w = cc0.constraint == DualContainerConstraint::use_all_available_space
                            ? size.getWidth() - cc1.control->getActualPreferredSize().getWidth()
                            : cc0.control->getActualPreferredSize().getWidth();

            auto c1w = size.getWidth() - c0w;

            cc0.control->setActualSize({c0w, size.getHeight()});
            cc1.control->setActualSize({c1w, size.getHeight()});

            cc0.control->setActualPosition(position);
            cc1.control->setActualPosition({position.getX() + c0w, position.getY()});
        }
    }
}