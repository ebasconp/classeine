#pragma once

#include "list_container.h"

#include "clsn/draw/point.h"

namespace clsn::ui
{
    using clsn::core::empty;

    class xy_container : public list_container<point>
    {
    public:
        xy_container();

        void do_layout() override;

    protected:
        auto make_default_renderer() const -> std::unique_ptr<renderer_base> override;
    };
}
