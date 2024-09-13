// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "toggle_control.h"

namespace clsn::ui
{
    class toggle_button : public toggle_control
    {
    public:
        toggle_button();

    protected:
        auto make_default_renderer() const -> std::unique_ptr<renderer_base> override;
    };
}