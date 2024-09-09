#pragma once

#include "layout_base.h"

#include <clsn/draw/region.h>

namespace clsn::ui::layouts
{
    enum class dual_layout_orientation
    {
        horizontal,
        vertical
    };

    enum class dual_layout_constraint
    {
        use_preferred_size,
        use_all_available_space
    };

    class dual_layout : public layout_base<dual_layout_constraint>
    {
        dual_layout_orientation m_orientation;

    public:
        using constraint_type = dual_layout_constraint;

        dual_layout();

        auto get_orientation() const -> dual_layout_orientation;
        void set_orientation(dual_layout_orientation orientation);

        void layout(const region& rgn) override;

    private:
        void layout_vertical(const point& position, const dimension& size);
        void layout_horizontal(const point& position, const dimension& size);
    };
}