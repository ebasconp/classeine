// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/ToggleButton.h>

#include <clsn/ui/renderers/ToggleButtonRenderer.h>

namespace clsn::ui
{
    ToggleButton::ToggleButton()
    : ToggleControl("ToggleButton")
    {

    }

    auto ToggleButton::makeDefaultRenderer() const -> std::unique_ptr<IRenderer>
    {
        return std::make_unique<renderers::ToggleButtonRenderer>();
    }
}