#pragma once

#include "layout_base.h"

#include <clsn/draw/forward.h>

namespace clsn::ui::layouts
{
    class xy_layout : public layout_base<point>
    {
    public:
        using constraint_type = point;

        void layout(const region& rgn) override;
    };
}