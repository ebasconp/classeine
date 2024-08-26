#include "dual_layout_container.h"

#include "renderers/dual_container_renderer.h"

#include "clsn/core/system.h"

namespace clsn::ui
{
    dual_layout_container::dual_layout_container()
    : layout_container<layouts::dual_layout>{"dual_layout_container"}
    {
    }


    auto dual_layout_container::get_orientation() const -> dual_layout_orientation
    {
        return m_orientation;
    }


    void dual_layout_container::set_orientation(dual_layout_orientation orientation)
    {
        m_orientation = orientation;
    }

    void dual_layout_container::check_if_valid_before_adding(const dual_layout_constraint& constraint) const
    {
        if (get_count() == 2)
            system::panic("Dual container can only contain two elements");

        if (get_count() == 1 && constraint == get_element_at(0).m_constraint)
            system::panic("Both controls must have different constraints");
    }


    auto dual_layout_container::make_default_renderer() const -> std::unique_ptr<renderer_base>
    {
        return std::make_unique<renderers::dual_container_renderer>();
    }
}