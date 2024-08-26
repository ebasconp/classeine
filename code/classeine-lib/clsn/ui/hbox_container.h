#pragma once

#include "list_container.h"

#include "layouts/hbox_layout.h"

namespace clsn::ui
{
    using clsn::core::empty;

    class hbox_container : public list_container<layouts::hbox_layout>
    {
    public:
        hbox_container();

    protected:
        auto make_default_renderer() const -> std::unique_ptr<renderer_base> override;
    };
}
