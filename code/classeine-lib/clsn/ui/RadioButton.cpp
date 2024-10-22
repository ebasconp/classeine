// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/RadioButton.h>

#include <clsn/ui/renderers/RadioButtonRenderer.h>

namespace clsn::ui
{
    RadioButton::RadioButton()
    : ToggleControl("RadioButton")
    {

    }

    void RadioButton::toggle()
    {
        if (!isChecked())
            setChecked(true);
    }

    auto RadioButton::makeDefaultRenderer() const -> std::unique_ptr<IRenderer>
    {
        return std::make_unique<renderers::RadioButtonRenderer>();
    }
}