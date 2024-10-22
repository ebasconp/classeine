// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/renderers/ButtonRenderer.h>

namespace  clsn::ui
{
    class ClickableControl;
}

namespace clsn::ui::renderers
{
    class ToggleButtonRenderer : public ButtonRenderer
    {
    public:
        [[nodiscard]] virtual auto paint_as_pressed(const ClickableControl& Button) const -> bool;
    };
}