#pragma once

#include "layout_container.h"

#include "layouts/flow_layout.h"

namespace clsn::ui
{
    using clsn::core::empty;

    class flow_layout_container : public layout_container<layouts::flow_layout>
    {
    public:
        flow_layout_container();

    protected:
        auto make_default_renderer() const -> std::unique_ptr<renderer_base> override;
    };
}
