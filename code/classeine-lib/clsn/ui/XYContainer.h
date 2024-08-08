#pragma once

#include "ListContainer.h"

#include "clsn/draw/point.h"

namespace clsn::ui
{
    using clsn::core::empty;

    class XYContainer : public ListContainer<point>
    {
    public:
        XYContainer();

        void doLayout() override;
    };
}
