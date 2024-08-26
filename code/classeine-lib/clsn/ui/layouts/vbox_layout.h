#pragma once

#include "layout_base.h"

#include <clsn/draw/forward.h>

#include <clsn/core/empty.h>


namespace clsn::ui::layouts
{
    class vbox_layout : public layout_base<core::empty>
    {
    public:
        using constraint_type = core::empty;

        void layout(const region& rgn) override;
    };
}