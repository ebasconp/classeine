#pragma once

#include "list_container.h"

namespace clsn::ui
{
    using clsn::core::empty;

    class vbox_container : public list_container<empty>
    {
    public:
        vbox_container();

        void do_layout() override;

    protected:
        auto make_default_renderer() const -> std::unique_ptr<renderer_base> override;
    };
}
