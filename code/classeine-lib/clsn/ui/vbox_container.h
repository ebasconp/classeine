#pragma once

#include "layout_container.h"

#include "layouts/vbox_layout.h"

namespace clsn::ui
{
    using clsn::core::empty;

    class vbox_container : public layout_container<layouts::vbox_layout>
    {
    public:
        vbox_container();

    protected:
        auto make_default_renderer() const -> std::unique_ptr<renderer_base> override;
    };
}
