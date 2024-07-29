#pragma once

#include "ListContainer.h"

#include "clsn/draw/Point.h"

namespace clsn::ui
{
    using clsn::core::Empty;

    class XYContainer : public ListContainer<Point>
    {
    public:
        XYContainer();

        void doLayout() override;
    };
}
