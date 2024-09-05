#include "dynamic_pane.h"

#include "renderers/dynamic_pane_renderer.h"

namespace clsn::ui
{
    using namespace clsn::ui::renderers;

    dynamic_pane::dynamic_pane() : control("dynamic_pane")
    {
    }

    void dynamic_pane::do_layout()
    {
        if (m_inner_control == nullptr)
            return;

        m_inner_control->set_actual_position(this->get_actual_position());
        m_inner_control->set_actual_size(this->get_actual_size());
        m_inner_control->do_layout();
    }

    auto dynamic_pane::make_default_renderer() const -> std::unique_ptr<renderer_base>
    {
        return std::make_unique<dynamic_pane_renderer>();
    }

    auto dynamic_pane::get_inner_control() -> std::shared_ptr<control>&
    {
        return m_inner_control;
    }

    auto dynamic_pane::get_inner_control() const -> const std::shared_ptr<control>&
    {
        return m_inner_control;
    }

    void dynamic_pane::set_inner_control(std::shared_ptr<control> ctrl)
    {
        if (m_inner_control.get() == ctrl.get())
            return;

        if (m_inner_control != nullptr)
        {
            m_inner_control->set_parent_control(std::nullopt);
            m_inner_control->set_parent_window(std::nullopt);
        }

        m_inner_control = ctrl;
        m_inner_control->set_parent_control(this->get_parent_control());
        m_inner_control->set_parent_window(this->get_parent_window());

        invalidate();
        m_inner_control->invalidate();
    }

    void dynamic_pane::invalidate() const noexcept
    {
        control::invalidate();

        if (m_inner_control != nullptr)
            m_inner_control->invalidate();
    }

    void dynamic_pane::validate() const noexcept
    {
        control::validate();

        if (m_inner_control != nullptr)
            m_inner_control->validate();
    }


}