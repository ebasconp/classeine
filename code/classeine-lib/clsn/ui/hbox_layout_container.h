#pragma once

#include "layout_container.h"

#include "layouts/hbox_layout.h"

namespace clsn::ui
{
    using clsn::core::empty;

    class hbox_layout_container : public layout_container<layouts::hbox_layout>
    {
    public:
        hbox_layout_container();

    protected:
        auto make_default_renderer() const -> std::unique_ptr<renderer_base> override;
    };
}
