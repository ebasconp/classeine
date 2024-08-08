#pragma once

#include "ListContainer.h"

namespace clsn::ui
{
    using clsn::core::empty;

    class VBoxContainer : public ListContainer<empty>
    {
    public:
        VBoxContainer();

        void doLayout() override;
    };
}
