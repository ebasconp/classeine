#pragma once

#include "ListContainer.h"

namespace clsn::ui
{
    using clsn::core::Empty;

    class HBoxContainer : public ListContainer<Empty>
    {
    public:
        HBoxContainer();

    private:
        void initEvents();
    };
}
