#pragma once

#include "ListContainer.h"

namespace clsn::ui
{
    enum DualContainerOrientation
    {
        horizontal,
        vertical
    };

    enum DualContainerConstraint
    {
        use_preferred_size,
        use_all_available_space
    };

    class DualContainer : public ListContainer<DualContainerConstraint>
    {
        DualContainerOrientation m_orientation;

    public:
        DualContainer();

        auto getOrientation() const -> DualContainerOrientation;
        void setOrientation(DualContainerOrientation orientation);

        void doLayout() override;

    protected:
        void checkIfValidBeforeAdding(const DualContainerConstraint& fill) const override;
    };
}