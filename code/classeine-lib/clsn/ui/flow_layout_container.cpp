// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "flow_layout_container.h"

#include "renderers/container_renderer.h"


namespace clsn::ui
{
    flow_layout_container::flow_layout_container()
    : layout_container("flow_container")
    {
    }

    auto flow_layout_container::make_default_renderer() const -> std::unique_ptr<renderer_base>
    {
        return std::make_unique<renderers::container_renderer<flow_layout_container>>();
    }

}