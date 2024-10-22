// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/layout_container.h>

#include <clsn/ui/layouts/hbox_layout.h>

namespace clsn::ui
{
    class hbox_layout_container : public layout_container<layouts::hbox_layout>
    {
    public:
        hbox_layout_container();

    protected:
        auto make_default_renderer() const -> std::unique_ptr<renderer_base> override;
    };
}
