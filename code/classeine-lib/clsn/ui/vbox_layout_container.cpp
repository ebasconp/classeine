// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/vbox_layout_container.h>

#include <clsn/ui/renderers/container_renderer.h>


namespace clsn::ui
{
    vbox_layout_container::vbox_layout_container()
    : layout_container("vbox_layout_container")
    {
    }

    auto vbox_layout_container::make_default_renderer() const -> std::unique_ptr<renderer_base>
    {
        return std::make_unique<renderers::container_renderer<vbox_layout_container>>();
    }
}