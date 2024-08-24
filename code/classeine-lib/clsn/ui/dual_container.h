#pragma once

#include "list_container.h"

#include "clsn/ui/layouts/dual_layout.h"

namespace clsn::ui
{
    using namespace clsn::ui::layouts;

    class dual_container : public list_container<dual_layout_constraint>
    {
        dual_layout_orientation m_orientation;

    public:
        dual_container();

        auto get_orientation() const -> dual_layout_orientation;
        void set_orientation(dual_layout_orientation orientation);

        void do_layout() override;

    protected:
        void check_if_valid_before_adding(const dual_layout_constraint& fill) const override;

        auto make_default_renderer() const -> std::unique_ptr<renderer_base> override;
    };
}