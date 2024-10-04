// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "toggle_control.h"

namespace clsn::ui
{
    CLSN_CPP_BOOL_PROPERTY(toggle_control, checked)

    toggle_control::toggle_control(std::string_view section_name)
    : clickable_control{section_name}
    {
        init_events();
    }

    void toggle_control::toggle()
    {
        set_checked(!is_checked());
    }

    void toggle_control::init_events()
    {
        add_action_listener([this](auto& )
        {
            toggle();
        });
    }
}