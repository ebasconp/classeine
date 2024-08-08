#pragma once

#include "list_container.h"

namespace clsn::ui
{
    using clsn::core::empty;

    class flow_container : public list_container<empty>
    {
    public:
        flow_container();

        void do_layout() override;
    };
}
