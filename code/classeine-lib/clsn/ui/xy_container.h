#pragma once

#include "layout_container.h"

#include "layouts/xy_layout.h"

namespace clsn::ui
{
    using clsn::core::empty;

    class xy_container : public layout_container<layouts::xy_layout>
    {
    public:
        xy_container();

    protected:
        auto make_default_renderer() const -> std::unique_ptr<renderer_base> override;
    };
}
