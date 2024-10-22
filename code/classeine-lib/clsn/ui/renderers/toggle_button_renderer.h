// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/renderers/button_renderer.h>

namespace  clsn::ui
{
    class clickable_control;
}

namespace clsn::ui::renderers
{
    class toggle_button_renderer : public button_renderer
    {
    public:
        [[nodiscard]] auto paint_as_pressed(const clickable_control& button) const -> bool override;
    };
}