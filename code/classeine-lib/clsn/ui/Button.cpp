// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "Button.h"

#include "renderers/ButtonRenderer.h"

namespace clsn::ui
{
    Button::Button()
    : ClickableControl("Button")
    {
    }

    auto Button::makeDefaultRenderer() const -> std::unique_ptr<IRenderer>
    {
        return std::make_unique<renderers::ButtonRenderer>();
    }
}