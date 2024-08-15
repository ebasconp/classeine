#include "dual_container.h"

#include "renderers/dual_container_renderer.h"

#include "clsn/core/system.h"

namespace clsn::ui
{
    dual_container::dual_container()
    : list_container<dual_container_constraint>{"dual_container"}
    , m_orientation{dual_container_orientation::vertical}
    {
    }


    auto dual_container::get_orientation() const -> dual_container_orientation
    {
        return m_orientation;
    }


    void dual_container::set_orientation(dual_container_orientation orientation)
    {
        m_orientation = orientation;
    }


    void dual_container::check_if_valid_before_adding(const dual_container_constraint& constraint) const
    {
        if (get_count() == 2)
            system::panic("Dual container can only contain two elements");

        if (get_count() == 1 && constraint == get_constraint_at(0))
            system::panic("Both controls must have different constraints");
    }


    void dual_container::do_layout()
    {
        const auto visibleCount = get_visible_count();
        if (visibleCount == 0)
            return;

        const auto& position = get_actual_position();
        const auto& size = get_actual_size();

        switch (m_orientation)
        {
            case dual_container_orientation::horizontal:
                doLayoutHorizontal(position, size);
                break;

            case dual_container_orientation::vertical:
                doLayoutVertical(position, size);
                break;
        }
    }

    void dual_container::doLayoutVertical(const point& position, const dimension& size)
    {
        const auto count = get_count();
        if (count == 1)
        {
            auto& cc = get_control_and_constraint_at(0);

            auto ch = cc.m_constraint == dual_container_constraint::use_all_available_space
                ? size.get_height()
                : cc.m_control->get_actual_preferred_size().get_height();

            cc.m_control->set_actual_size({size.get_width(), ch});
            cc.m_control->set_actual_position(position);
            cc.m_control->do_layout();
            return;
        }

        if (count == 2)
        {
            auto& cc0 = get_control_and_constraint_at(0);
            auto& cc1 = get_control_and_constraint_at(1);

            auto c0h = cc0.m_constraint == dual_container_constraint::use_all_available_space
                            ? size.get_height() - cc1.m_control->get_actual_preferred_size().get_height()
                            : cc0.m_control->get_actual_preferred_size().get_height();

            auto c1h = size.get_height() - c0h;

            cc0.m_control->set_actual_size({size.get_width(), c0h});
            cc1.m_control->set_actual_size({size.get_width(), c1h});

            cc0.m_control->set_actual_position(position);
            cc1.m_control->set_actual_position({position.get_x(), position.get_y() + c0h});

            cc0.m_control->do_layout();
            cc1.m_control->do_layout();
        }
    }


    void dual_container::doLayoutHorizontal(const point& position, const dimension& size)
    {
        const auto count = get_count();
        if (count == 1)
        {
            auto& cc = get_control_and_constraint_at(0);

            auto cw = cc.m_constraint == dual_container_constraint::use_all_available_space
                ? size.get_width()
                : cc.m_control->get_actual_preferred_size().get_width();

            cc.m_control->set_actual_size({cw, size.get_height()});
            cc.m_control->set_actual_position(position);
            cc.m_control->do_layout();
            return;
        }

        if (count == 2)
        {
            auto& cc0 = get_control_and_constraint_at(0);
            auto& cc1 = get_control_and_constraint_at(1);

            auto c0w = cc0.m_constraint == dual_container_constraint::use_all_available_space
                            ? size.get_width() - cc1.m_control->get_actual_preferred_size().get_width()
                            : cc0.m_control->get_actual_preferred_size().get_width();

            auto c1w = size.get_width() - c0w;

            cc0.m_control->set_actual_size({c0w, size.get_height()});
            cc1.m_control->set_actual_size({c1w, size.get_height()});

            cc0.m_control->set_actual_position(position);
            cc1.m_control->set_actual_position({position.get_x() + c0w, position.get_y()});

            cc0.m_control->do_layout();
            cc1.m_control->do_layout();
        }
    }

    auto dual_container::make_default_renderer() const -> std::unique_ptr<renderer_base>
    {
        return std::make_unique<renderers::dual_container_renderer>();
    }
}