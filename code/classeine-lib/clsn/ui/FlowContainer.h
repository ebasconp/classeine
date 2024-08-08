#pragma once

#include "ListContainer.h"

namespace clsn::ui
{
    using clsn::core::empty;

    class FlowContainer : public ListContainer<empty>
    {
    public:
        FlowContainer();

        void doLayout() override;
    };
}
