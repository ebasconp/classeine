#include "DualContainer.h"

#include "clsn/core/system.h"

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
            system::panic("Dual container can only contain two elements");

        if (getCount() == 1 && constraint == getConstraintAt(0))
            system::panic("Both controls must have different constraints");
    }


    void DualContainer::do_layout()
    {
        const auto visibleCount = get_visible_count();
        if (visibleCount == 0)
            return;

        const auto& position = get_actual_position();
        const auto& size = get_actual_size();

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

    void DualContainer::doLayoutVertical(const point& position, const dimension& size)
    {
        const auto count = getCount();
        if (count == 1)
        {
            auto& cc = getControlAndConstraintAt(0);

            auto ch = cc.m_constraint == DualContainerConstraint::use_all_available_space
                ? size.get_height()
                : cc.m_control->get_actual_preferred_size().get_height();

            cc.m_control->set_actual_size({size.get_width(), ch});
            cc.m_control->set_actual_position(position);
            return;
        }

        if (count == 2)
        {
            auto& cc0 = getControlAndConstraintAt(0);
            auto& cc1 = getControlAndConstraintAt(1);

            auto c0h = cc0.m_constraint == DualContainerConstraint::use_all_available_space
                            ? size.get_height() - cc1.m_control->get_actual_preferred_size().get_height()
                            : cc0.m_control->get_actual_preferred_size().get_height();

            auto c1h = size.get_height() - c0h;

            cc0.m_control->set_actual_size({size.get_width(), c0h});
            cc1.m_control->set_actual_size({size.get_width(), c1h});

            cc0.m_control->set_actual_position(position);
            cc1.m_control->set_actual_position({position.get_x(), position.get_y() + c0h});
        }
    }


    void DualContainer::doLayoutHorizontal(const point& position, const dimension& size)
    {
        const auto count = getCount();
        if (count == 1)
        {
            auto& cc = getControlAndConstraintAt(0);

            auto cw = cc.m_constraint == DualContainerConstraint::use_all_available_space
                ? size.get_width()
                : cc.m_control->get_actual_preferred_size().get_width();

            cc.m_control->set_actual_size({cw, size.get_height()});
            cc.m_control->set_actual_position(position);
            return;
        }

        if (count == 2)
        {
            auto& cc0 = getControlAndConstraintAt(0);
            auto& cc1 = getControlAndConstraintAt(1);

            auto c0w = cc0.m_constraint == DualContainerConstraint::use_all_available_space
                            ? size.get_width() - cc1.m_control->get_actual_preferred_size().get_width()
                            : cc0.m_control->get_actual_preferred_size().get_width();

            auto c1w = size.get_width() - c0w;

            cc0.m_control->set_actual_size({c0w, size.get_height()});
            cc1.m_control->set_actual_size({c1w, size.get_height()});

            cc0.m_control->set_actual_position(position);
            cc1.m_control->set_actual_position({position.get_x() + c0w, position.get_y()});
        }
    }
}