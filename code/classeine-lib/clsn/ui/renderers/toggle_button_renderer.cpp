// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "toggle_button_renderer.h"

#include "clsn/ui/toggle_button.h"

namespace clsn::ui::renderers
{
    using namespace clsn::draw;
    using namespace clsn::ui;

    auto toggle_button_renderer::paint_as_pressed(const clickable_control& button) const -> bool
    {
        return static_cast<const toggle_button&>(button).isChecked() || button.is_pressed();
    }
}