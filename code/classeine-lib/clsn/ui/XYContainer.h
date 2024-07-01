#pragma once

#include "ListContainer.h"

#include "clsn/draw/Region.h"

namespace clsn::ui
{
    using clsn::core::Empty;

    class XYContainer : public ListContainer<Region>
    {
    public:
        XYContainer();

    private:
        void initEvents();
    };
}
