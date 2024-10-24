// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/tab_control.h>

namespace clsn::ui
{
    tab_control::tab_control()
    : base_class{*this}
    , m_view{get_inner_control()}
    {
        //ETOTODO
        //m_header = this->get_inner_control().make_and_add<_private::tab_pane_header>();
    }

    void tab_control::set_active_index(std::optional<int> index)
    {
        m_active_index = index;

        m_view.set_active_index(index);
    }

    auto tab_control::get_active_index() const -> std::optional<int>
    {
        return m_active_index;
    }


}