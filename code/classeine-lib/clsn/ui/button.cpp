// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/button.h>

#include <clsn/ui/renderers/button_renderer.h>

namespace clsn::ui
{
    button::button()
    : clickable_control("button")
    {
    }

    auto button::make_default_renderer() const -> std::unique_ptr<renderer_base>
    {
        return std::make_unique<renderers::button_renderer>();
    }
}