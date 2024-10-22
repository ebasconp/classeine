// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/layout_container.h>

#include <clsn/ui/layouts/flow_layout.h>

namespace clsn::ui
{
    class flow_layout_container : public layout_container<layouts::flow_layout>
    {
    public:
        flow_layout_container();

    protected:
        auto make_default_renderer() const -> std::unique_ptr<renderer_base> override;
    };
}
