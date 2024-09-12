// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "empty_control.h"

#include "renderers/empty_control_renderer.h"

namespace clsn::ui
{
    empty_control::empty_control()
    : control{""}
    {
    }

    auto empty_control::make_default_renderer() const -> std::unique_ptr<renderer_base>
    {
        return std::make_unique<renderers::empty_control_renderer>();
    }
}