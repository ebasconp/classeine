// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/check_box.h>

#include <clsn/ui/renderers/check_box_renderer.h>

namespace clsn::ui
{
    check_box::check_box()
    : toggle_control("check_box")
    {

    }

    auto check_box::make_default_renderer() const -> std::unique_ptr<renderer_base>
    {
        return std::make_unique<renderers::check_box_renderer>();
    }
}