// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "ToggleButtonRenderer.h"

#include "clsn/ui/ToggleButton.h"

namespace clsn::ui::renderers
{
    using namespace clsn::draw;
    using namespace clsn::ui;

    auto ToggleButtonRenderer::paint_as_pressed(const ClickableControl& Button) const -> bool
    {
        return static_cast<const ToggleButton&>(Button).isChecked() || Button.isPressed();
    }
}