// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/tab_control.h>

namespace clsn::ui
{
    tab_control::tab_control(std::string_view section_name)
    : base_class(section_name)
    {
        //ETOTODO
        //m_header = this->get_inner_control().make_and_add<_private::tab_pane_header>();
    }

}