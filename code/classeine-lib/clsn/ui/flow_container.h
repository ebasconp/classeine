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

    protected:
        auto make_default_renderer() const -> std::unique_ptr<renderer_base> override;
    };
}
