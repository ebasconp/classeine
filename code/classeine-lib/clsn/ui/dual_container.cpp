#include "dual_container.h"

#include "layouts/dual_layout.h"

#include "renderers/dual_container_renderer.h"

#include "clsn/core/system.h"

namespace clsn::ui
{
    dual_container::dual_container()
    : list_container<dual_layout_constraint>{"dual_container"}
    , m_orientation{dual_layout_orientation::vertical}
    {
    }


    auto dual_container::get_orientation() const -> dual_layout_orientation
    {
        return m_orientation;
    }


    void dual_container::set_orientation(dual_layout_orientation orientation)
    {
        m_orientation = orientation;
    }


    void dual_container::check_if_valid_before_adding(const dual_layout_constraint& constraint) const
    {
        if (get_count() == 2)
            system::panic("Dual container can only contain two elements");

        if (get_count() == 1 && constraint == get_element_at(0).m_constraint)
            system::panic("Both controls must have different constraints");
    }


    void dual_container::do_layout()
    {
        const auto visibleCount = get_visible_count();
        if (visibleCount == 0)
            return;

        using namespace clsn::ui::layouts;
        dual_layout layout{m_orientation};

        this->iterate_elements([&](control_and_constraint& e)
        {
            layout.add(
                {e.m_control->get_actual_position(), e.m_control->get_actual_preferred_size()},
                e.m_constraint);
        });

        layout.layout(get_actual_bounds());

        int count = layout.get_count();
        for (int i = 0, j = 0; i < count; i++)
        {
            auto& ctrl = (*this)[i];
            if (!ctrl.is_visible())
                continue;

            auto& rgn = layout.get_element_at(j).m_region;

            ctrl.set_actual_position(rgn.get_position());
            ctrl.set_actual_size(rgn.get_size());

            j++;
        }
    }

    auto dual_container::make_default_renderer() const -> std::unique_ptr<renderer_base>
    {
        return std::make_unique<renderers::dual_container_renderer>();
    }
}