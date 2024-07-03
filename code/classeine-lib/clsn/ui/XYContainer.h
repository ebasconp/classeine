#pragma once

#include "ListContainer.h"

#include "clsn/draw/Region.h"

namespace clsn::ui
{
    using clsn::core::Empty;

    class XYContainer : public ListContainer<Region>
    {
    public:
        using BaseContainer = ListContainer<Region>;

        XYContainer();

    private:
        void initEvents();
    };
}
