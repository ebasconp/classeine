// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "dynamic_content_pane.h"

namespace clsn::ui
{
    using namespace clsn::draw;

    dynamic_content_pane::dynamic_content_pane() : content_pane("dynamic_content_pane")
    {
    }

    auto dynamic_content_pane::get_inner_control() -> std::shared_ptr<control>&
    {
        return m_inner_control;
    }

    auto dynamic_content_pane::get_inner_control() const -> const std::shared_ptr<control>&
    {
        return m_inner_control;
    }

    void dynamic_content_pane::set_inner_control(const std::shared_ptr<control>& ctrl)
    {
        if (m_inner_control.get() == ctrl.get())
            return;

        if (m_inner_control != nullptr)
        {
            m_inner_control->set_parent_control(std::nullopt);
            m_inner_control->set_parent_window(std::nullopt);
        }

        m_inner_control = ctrl;

        if (ctrl != nullptr)
        {
            m_inner_control->set_parent_window(this->get_parent_window());
            m_inner_control->set_parent_control(*this);
        }

        do_layout();
        invalidate();
    }

    auto dynamic_content_pane::get_actual_inner_control() -> core::optional_reference<control>
    {
        if (m_inner_control == nullptr)
            return {};

        return *m_inner_control.get();
    }

    auto dynamic_content_pane::get_actual_inner_control() const -> core::const_optional_reference<control>
    {
        if (m_inner_control == nullptr)
            return {};

        return *m_inner_control.get();
    }
}