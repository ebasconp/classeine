#pragma once

#include "ListContainer.h"

namespace clsn::ui
{
    using clsn::core::Empty;

    class VBoxContainer : public ListContainer<Empty>
    {
    public:
        VBoxContainer();

    private:
        void initEvents();
    };
}
