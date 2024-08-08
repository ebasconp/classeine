#pragma once

#include "ListContainer.h"

namespace clsn::ui
{
    using clsn::core::empty;

    class HBoxContainer : public ListContainer<empty>
    {
    public:
        HBoxContainer();

        void do_layout() override;
    };
}
