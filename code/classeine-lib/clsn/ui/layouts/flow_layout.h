#pragma once

#include "layout_base.h"

#include <clsn/draw/forward.h>

#include <clsn/core/empty.h>


namespace clsn::ui::layouts
{
    class flow_layout : public layout_base<core::empty>
    {
    public:
        using constraint_type = core::empty;

        void layout(const region& rgn) override;

    private:
        void layout_vertical(const point& position, const dimension& size);
        void layout_horizontal(const point& position, const dimension& size);
    };
}