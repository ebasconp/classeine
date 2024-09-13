// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "toggle_control.h"

namespace clsn::ui
{
    class check_box : public toggle_control
    {
    public:
        check_box();

    protected:
        auto make_default_renderer() const -> std::unique_ptr<renderer_base> override;
    };
}