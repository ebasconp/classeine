#pragma once

#include "list_container.h"

namespace clsn::ui
{
    enum class dual_container_orientation
    {
        horizontal,
        vertical
    };

    enum class dual_container_constraint
    {
        use_preferred_size,
        use_all_available_space
    };

    class dual_container : public list_container<dual_container_constraint>
    {
        dual_container_orientation m_orientation;

    public:
        dual_container();

        auto get_orientation() const -> dual_container_orientation;
        void set_orientation(dual_container_orientation orientation);

        void do_layout() override;

    protected:
        void check_if_valid_before_adding(const dual_container_constraint& fill) const override;

    private:
        void doLayoutVertical(const point& position, const dimension& size);
        void doLayoutHorizontal(const point& position, const dimension& size);
    };
}