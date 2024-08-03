#pragma once

#include "ListContainer.h"

namespace clsn::ui
{
    using clsn::core::Empty;

    class FlowContainer : public ListContainer<Empty>
    {
    public:
        FlowContainer();

        void doLayout() override;
    };
}
