// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "ToggleControl.h"

namespace clsn::ui
{
    CLSN_CPP_BOOL_PROPERTY(ToggleControl, Checked)

    ToggleControl::ToggleControl(std::string_view sectionName)
    : ClickableControl{sectionName}
    {
        initToggleControlEvents();
    }

    void ToggleControl::toggle()
    {
        setChecked(!isChecked());
    }

    void ToggleControl::initToggleControlEvents()
    {
        addActionListener([this](auto& )
        {
            toggle();
        });
    }
}